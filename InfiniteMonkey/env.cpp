#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

class Monkey {
    public:
        char alphabet[26];
        int size;
        std::string matchString;

        std::string longestMatch;
        int passes = 0;

        Monkey(char alpha[26], int s, std::string word){
            size = s;
            matchString = word;
            for(int i = 0; i <size ; i++){
                alphabet[i] = alpha[i];
            }
        }

        std::string MonkeyType(){
            int i = 0;
            std::string currentMatch = "";
            longestMatch = "";
            while(longestMatch != matchString){
                // Get random character from aplhabet
                int ranIndex = rand() % 26;
                char newChar = alphabet[ranIndex];
                // Assign the character we are currently matching too
                char matchChar = matchString[i];
                // Print the current depth, the character we want to match, the character we guess
                std::cout << i << ": " << matchChar << newChar << "\n";
                // If the two character match
                if(matchChar == newChar){
                    // Make the Character a string
                    std::string s(1,newChar);
                    // Concat the string with the rest of the current run
                    currentMatch = currentMatch + s;
                    // Increase depth
                    i++;
                    // If the current depth is better than we've done previously update the best we've done
                    if(currentMatch.length() > longestMatch.length()){
                        longestMatch = currentMatch;
                    }
                }
                //If the guess is wrong reset from the beginning
                else {
                    i = 0;
                    currentMatch = "";
                }
            }
            // Once we've finally recreated the word return it
            return currentMatch;
        }

        void ShowStats(){
            std::cout << "Size: " << size << "\n" << "Word to match: " << matchString << "\n" << "Alphabet: " << alphabet << "\n";
        }

};

int main() {

    std::string matchString;
    const int size = 26;
    char alphabet[size] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    std::cout <<"Input string you would like to match: \n";
    std::cin >> matchString;
    std::cin.get();

    Monkey monkey(alphabet, size, matchString);
    monkey.ShowStats();
    std::cout << monkey.MonkeyType() << "\n";
    
}
