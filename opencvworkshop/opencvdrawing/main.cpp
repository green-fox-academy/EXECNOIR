#include <iostream>
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <sqlite3.h>

#define PI 3.14159265

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


typedef enum quadrant{
    TOP_RIGHT,
    TOP_LEFT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT
}quadrant_t;

quadrant_t quadrant = TOP_RIGHT;
sqlite3 *db;
char *zErrMsg = 0;
int rc;
char* sql;
char buffer[50];
char DrawingWindow[] = "Drawing";
cv::Point point;
cv::Point tracker;
cv::Mat image = cv::Mat::zeros(400, 400, CV_8UC3);

double getAngle(cv::Point point);
void CircleInTheMiddle(cv::Mat image, cv::Point center);
void LineFromTheRight(cv::Mat image, cv::Point start, cv::Point end);
void mouseHandler(int, int, int, int, void*);

int main() {

    rc = sqlite3_open("../angles.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    CircleInTheMiddle(image, cv::Point(400/2,400/2));
    LineFromTheRight(image, cv::Point(400/2, 400/2), cv::Point(400, 400/2));


    cv::namedWindow("Drawing", cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback( "Drawing", mouseHandler, 0 );
    cv::imshow(DrawingWindow, image);
    cv::waitKey(0);


    return 0;
}

void CircleInTheMiddle(cv::Mat image, cv::Point center)
{
    cv::circle(image, center, 400/32, cv::Scalar(255, 255, 255), 2, cv::LINE_8);
}

void LineFromTheRight(cv::Mat image, cv::Point start, cv::Point end)
{
    cv::line(image, start, end, cv::Scalar(255,255,255), 2, cv::LINE_8);
}

void mouseHandler(int event, int x, int y, int, void*)
{
    if(event == cv::EVENT_LBUTTONDOWN)
    {
            point = cv::Point(x, y);
            printf("%d, %d\n",point.x, point.y );
            cv::line(image, point, cv::Point(400/2, 400/2), cv::Scalar(255,255,255), 2, cv::LINE_8);
            cv::line(image, point, cv::Point(point.x, 400/2), cv::Scalar(255, 255, 255), 2, cv::LINE_8);
            sprintf(buffer, "INSERT INTO angles(date, angle) VALUES( DATETIME(), %.2f );", getAngle(point));
            rc = sqlite3_exec(db, buffer, callback, 0, &zErrMsg);

            if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
            } else {
                fprintf(stdout, "Records created successfully\n");
            }

                cv::imshow(DrawingWindow, image);

    }
}

double getAngle(cv::Point point)
{
    int a;
    int b;
    if(point.x > 200 && point.y < 200) //top-right
    {
        a = point.x - 200;
        b = 200 - point.y;
        quadrant = TOP_RIGHT;
    }else if(point.x < 200 && point.y < 200 ) //top-left
    {
        a = 200 - point.x;
        b = 200 - point.y;
        quadrant = TOP_LEFT;
    }else if(point.x < 200 && point.y > 200) //bottom-left
    {
        a = 200 - point.x;
        b = point.y - 200;
        quadrant = BOTTOM_LEFT;
    }else if(point.x > 200 && point.y > 200) //bottom-right
    {
        a = point.x - 200;
        b = point.y - 200;
        quadrant = BOTTOM_RIGHT;
    }
    double c = sqrt((double)a*(double)a + (double)b*(double)b);
    //printf("%d, %d, %.f\n", a, b, c);
    double angle = asin(b/c)* 180 / PI;
    //printf("%.2f, %.2f\n", b/c, angle);
    switch(quadrant) {
        case TOP_RIGHT:
            return angle;
        case TOP_LEFT:
            return 180-angle;
        case BOTTOM_LEFT:
            return 180+angle;
        case BOTTOM_RIGHT:
            return 360-angle;
    }



    return 0;
}