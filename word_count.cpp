#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//Creates the class that keeps track of the number of times the word is used as well as the word that's repeated
class wordProperty{
    public:
        int count; //Number of occurances of word
        string strWord; //Word
};


//Function created to change string to entirely lowercase
string strLower(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower); //This is designed to itterate through each letter of the string and convert it to lowercase
    return text;
}


//Function used to obtain name of file from user
string getFileName() {
    string fileName;
    cout << "Text Document Name: ";
    cin >> fileName;
    return fileName;
}


//Main function
int main() {
    string fileName = getFileName(); //Obtains filename from function
    ifstream myFile; //Sets myFile to ifstream. This allows the software to access the .txt file
    myFile.open(fileName.c_str()); //Attempts to open file

    if (myFile.is_open()){ //Checks to see if the file was open.
        //Initializes variables
        int count; 
        string word;
        vector <wordProperty> wordList;
        //Creates a while loop that seperates .txt document by whitespace

        while (myFile >> word){
            word = strLower(word); //Changes current word to lowercase
            count += 1; //Keeps track of the number of itterations to know the total number of words in .txt file

            if (wordList.size() == 0){ //The vector is initialized empty. We use this to automatically add the first word
                //Sets class and variables
                wordProperty x;
                x.count = 1;
                x.strWord = word;
                wordList.push_back(x); //Adds word to list

            } else{
                //Resets variables for new loop
                wordProperty i;
                bool newWord = true;
                int loopCount = 0;

                for (int i = 0; i < wordList.size(); i++){ //The for loop iterates through each item in vector. 
                    //Checks if word is already in vector. If it is, it increases the word's count and breaks the loop. If not, the loop continues until it finds it or all words have been checked
                    
                    if (wordList[i].strWord == word){
                        wordList[i].count += 1;
                        newWord = false;
                        break;
                    }
                }
                //If the loop didn't find the current word within the wordList vector, it creates a new entry in the vector for the new word.
                if (newWord == true){
                    wordProperty y;
                    y.count = 1;
                    y.strWord = word;
                    wordList.push_back(y);
                }
            }
        }
        //Creates variables for the comparison of most common word
        int highWordCount = 0;
        string highWord;
        wordProperty z;
        //The for loop runs through each object in the vector to compare as to who is has the highest word count.
        for (auto z : wordList){
            
            if (z.count > highWordCount){
                highWordCount = z.count;
                highWord = z.strWord;
            }
        }
        //Prints the word count and the word that occurs the highest
        cout << "There are " << count << " words in your document";
        cout << "\n";
        cout << "The most common word was '" << highWord << "' and it occured " << highWordCount << " times.";
        myFile.close();

    } else { //Prints error message if the text file wasn't able to open
        cout << "Can't open file.";
    }
}