/******************************************************************************
 * Author: Juan Du
 * Date: 2017/03/04
 * Description:lab8 - practice sorting and searching algorithm
******************************************************************************/

#include "input.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

std::vector<float> readDataFromFile();
void printData(std::vector<float> numbers);

int main()
{
    
  std::vector<float> numbers = readDataFromFile();
  printData(numbers);
  return 0;
}

  
/***********************************************************************
 * helper function that read an input file into a dataset. 
***********************************************************************/
std::vector<float> readDataFromFile()
{
  std::ifstream myFile;
  std::ofstream outputFile ("output.txt");
  std::ofstream predFile ("predict.txt");
  std::vector<float> numbers;
  std::string dataString;
  std::vector<std::string> stringVec;
  std::string fileName = "semeion.txt";
  myFile.open(fileName);
  while (myFile.fail())
  {
    std::cout<<"Cannot find file "<<fileName;
    return numbers;
  }
  myFile >> dataString;
  while (std::getline(myFile,dataString)) {

    stringVec = split(dataString,' '); 
    if (stringVec[256]=="1") 
    {
      outputFile<<"\"ZERO\""<<",";
      predFile<<"\"ZERO\""<<",";
    }
    if (stringVec[257]=="1") 
    {
      outputFile<<"\"ONE\""<<",";
      predFile<<"\"ONE\""<<",";
    }
    if (stringVec[258]=="1") 
    {
      outputFile<<"\"TWO\""<<",";
      predFile<<"\"TWO\""<<",";
    }
    if (stringVec[259]=="1") 
    {
      outputFile<<"\"THREE\""<<",";
      predFile<<"\"THREE\""<<",";
    }
    if (stringVec[260]=="1") 
    {
      outputFile<<"\"FOUR\""<<",";
      predFile<<"\"FOUR\""<<",";
    }
    if (stringVec[261]=="1") 
    {
      outputFile<<"\"FIVE\""<<",";
      predFile<<"\"FIVE\""<<",";
    }
    if (stringVec[262]=="1") 
    {
      outputFile<<"\"SIX\""<<",";
      predFile<<"\"SIX\""<<",";
    }
    if (stringVec[263]=="1") 
    {
      outputFile<<"\"SEVEN\""<<",";
      predFile<<"\"SEVEN\""<<",";
    }
    if (stringVec[264]=="1") 
    {
      outputFile<<"\"EIGHT\""<<",";
      predFile<<"\"EIGHT\""<<",";
    }
    if (stringVec[265]=="1") 
    {
      outputFile<<"\"NINE\""<<",";
      predFile<<"\"NINE\""<<",";
    }
    for (int i = 0; i<256; ++i)
    {
      outputFile<<"\""<<stringVec[i][0]<<"\""<<",";
      predFile<<stringVec[i][0]<<",";
    }
    outputFile<<std::endl;
    predFile<<std::endl;
    
  }
  myFile.close();
  outputFile.close();
  predFile.close();
  return numbers;
}

  

/***********************************************************************
 * helper function that prints out the values in a given vector 
***********************************************************************/
void printData(std::vector<float> numbers)
{
  for (int val:numbers)
  {
    std::cout<<val<<" ";
  }
  std::cout<<std::endl;
}
