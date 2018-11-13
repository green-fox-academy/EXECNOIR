//
// Created by EXEC_NOIR on 11/13/2018.
//

#ifndef BLOGPOST_BLOGPOST_H
#define BLOGPOST_BLOGPOST_H
#include <iostream>

class BlogPost {
public:
    BlogPost(std::string authorName, std::string title, std::string text, std::string publicationDate);

    std::string GetAuthorName();
    std::string GetTitle();
    std::string GetText();
    std::string GetPublicationDate();

private:
    std::string _authorName;
    std::string _title;
    std::string _text;
    std::string _publicationDate;
};


#endif //BLOGPOST_BLOGPOST_H
