//
// Created by EXEC_NOIR on 11/13/2018.
//

#include "BlogPost.h"

BlogPost::BlogPost(std::string authorName, std::string title, std::string text, std::string publicationDate) {
    _authorName = authorName;
    _title = title;
    _text = text;
    _publicationDate = publicationDate;
}

std::string BlogPost::GetAuthorName() {
    return _authorName;
}

std::string BlogPost::GetTitle() {
    return _title;
}

std::string BlogPost::GetText() {
    return _text;
}

std::string BlogPost::GetPublicationDate() {
    return _publicationDate;
}