#include <iostream>
#include "BlogPost.h"

int main() {
    BlogPost post1("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet", "2000.05.04.");
    BlogPost post2("Tim Urban", "Wait but why",
                   "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10."
    );
    BlogPost post3("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump",
                   "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention.\n"
                   " When I asked to take his picture outside one of IBM’s New York City offices,\n "
                   "he told me that he wasn’t really into the whole organizer profile thing.",
                   "2017.03.28..");


    std::cout << "First Blog Post: " << std::endl <<
              post1.GetTitle() << std::endl <<
              post1.GetAuthorName() << std::endl <<
              post1.GetPublicationDate() << std::endl <<
              post1.GetText() << std::endl;
    std::cout << "Second Blog Post: " << std::endl <<
              post2.GetTitle() << std::endl <<
              post2.GetAuthorName() << std::endl <<
              post2.GetPublicationDate() << std::endl <<
              post2.GetText() << std::endl;
    std::cout << "Third Blog Post: " << std::endl <<
              post3.GetTitle() << std::endl <<
              post3.GetAuthorName() << std::endl <<
              post3.GetPublicationDate() << std::endl <<
              post3.GetText() << std::endl;
    return 0;
}