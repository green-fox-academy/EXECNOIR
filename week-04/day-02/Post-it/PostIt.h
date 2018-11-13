
#ifndef POST_IT_POSTIT_H
#define POST_IT_POSTIT_H

#include <iostream>

class PostIt {
public:
    PostIt();
    PostIt(std::string textColor, std::string text, std::string SetBackgroundColor);

    std::string GetTextColor();
    std::string GetText();
    std::string GetBackgroundColor();

private:
    std::string _textColor;
    std::string _text;
    std::string _backgroundColor;
};


#endif //POST_IT_POSTIT_H
