#include "snowman.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <array>
const int MAX_LEN_OF_NUMBER = 8;
const int BASE_OF_THE_NUMBER = 10;
const int HAT = 0;
const int NOSE = 1;
const int LEFT_EYE = 2;
const int RIGHT_EYE = 3;
const int LEFT_ARM = 4;
const int RIGHT_ARM = 5;
const int TORSO = 6;
const int BASE = 7;
using namespace std;

array<array<string,4>,MAX_LEN_OF_NUMBER>snowmanParts={{
    {"\n _===_ \n","  ___  \n ..... \n","   _   \n  /_\\  \n","  ___  \n (_*_) \n"},
    {",",".","_"," "},
    {".","o","O","-"},
    {".","o","O","-"},
    {"<","\\","/"," "},
    {">","/","\\"," "},
    {"( : )","(] [)","(> <)","(   )"},
    {" ( : ) "," (\" \") "," (___) "," (   ) "},
}};//array with all the option of snowman parts.
//function that get int num and check that the len is 8 and each digit is one of 1/2/3/4
bool checkNumber(int num)
{
    int ans=0;//count the digits
    while(num!=0)
    {
        if(num%BASE_OF_THE_NUMBER>4||num%BASE_OF_THE_NUMBER==0)//check that the digit is 1/2/3/4
        {
            return false;
        }
        num=num/BASE_OF_THE_NUMBER;//remove the last digit
        ans++;
    }
    return (ans==MAX_LEN_OF_NUMBER);//if the number of digits is 8 return true
}
namespace ariel
{
    string snowman(int num)
    {  
        //check that the number is not 0 or negative number
        if(num<=0){
             throw std::out_of_range{"the number is not positive"};
        }
        //check that the len of the number is 8 and that all the digit of the number is 1/2/3/4
        if(!checkNumber(num)){
            throw std::out_of_range{"Invalid number"};
        }
        const int baseNumber=num%BASE_OF_THE_NUMBER-1;//the number of the base of the snowman -1 because the array start from 0
        string snowmanAns=snowmanParts.at(BASE).at(baseNumber);//add the base of the snowman to the string
        num=num/BASE_OF_THE_NUMBER;//remove the last digit

        int torsoNumber=num%BASE_OF_THE_NUMBER-1;//num of the torso
        num=num/BASE_OF_THE_NUMBER;//remove the last digit

        int armRaightNumber=num%BASE_OF_THE_NUMBER-1;
        num=num/BASE_OF_THE_NUMBER;//remove the last digit

        int armLeftNumber=num%BASE_OF_THE_NUMBER-1;
        num=num/BASE_OF_THE_NUMBER;//remove the last digit

        int eyeRightNumber=num%BASE_OF_THE_NUMBER-1;
        num=num/BASE_OF_THE_NUMBER;//remove the last digit

        int eyeLeftNumber=num%BASE_OF_THE_NUMBER-1;
        num=num/BASE_OF_THE_NUMBER;//remove the last digit

        int noseNumber=num%BASE_OF_THE_NUMBER-1;
        int hatNumber=num/BASE_OF_THE_NUMBER-1;//remove the last digit
        
        if(armRaightNumber!=1){//if the number of the right arm is not 2 the right arm is next to the torso
           snowmanAns=snowmanParts.at(TORSO).at(torsoNumber)+snowmanParts.at(RIGHT_ARM).at(armRaightNumber)+"\n"+snowmanAns;//add torso to the snowmanAns 
        }
        else  {
            snowmanAns=snowmanParts.at(TORSO).at(torsoNumber)+"\n"+snowmanAns;//the are is next to the face of the snowman
        }
        
        if(armLeftNumber!=1){//if the num of the left arm is not 2
           snowmanAns=snowmanParts.at(LEFT_ARM).at(armLeftNumber)+snowmanAns;
        }
        else  {
            snowmanAns=" "+snowmanAns;
        }

        if(armRaightNumber==1){//add the arm right next to the face of the snowman
            snowmanAns="/\n"+snowmanAns;
        }
        else{
            snowmanAns=" \n"+snowmanAns;
        }
        snowmanAns="("+snowmanParts.at(LEFT_EYE).at(eyeLeftNumber)+snowmanParts.at(NOSE).at(noseNumber)+snowmanParts.at(RIGHT_EYE).at(eyeRightNumber)+")"+snowmanAns;//add the eyes and the nose

        //add the left arm 
        if(armLeftNumber==1){
            snowmanAns="\\"+snowmanAns;
        }
        else{
             snowmanAns=" "+snowmanAns;
        }

        return snowmanParts.at(HAT).at(hatNumber)+snowmanAns+"\n";//add the hat 
    }
}