#include "PostIt.h"
PostIt::PostIt() {

}

PostIt::PostIt(std::string textColor, std::string text, std::string backgroundColor){
    _textColor = textColor;
    _text = text;
    _backgroundColor = backgroundColor;
}

std::string PostIt::GetTextColor(){
    return _textColor;
}
std::string PostIt::GetText(){
    return _text;
}
std::string PostIt::GetBackgroundColor(){
    return _backgroundColor;
}