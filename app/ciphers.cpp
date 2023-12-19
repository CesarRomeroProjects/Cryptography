#include <string>
#include "ciphers.hpp"

/* 
 * Right now, these functions are stubbed;  that will allow this project
   to compile before you finish everything, and allow you to incrementally
   test your code, but are not expected to return the correct answers.
 */


std::string encryptShift(const std::string &message, unsigned key)
{
    // Created a new string object here since the string object
    // inside the parameter contains a const, hence it cannot be modified.
    std::string encryptedMessage{message};
    for(int counter{0}; counter < int(message.length()); counter++)
    {
        if(message[counter] != ' ') // Validating whether the character is a letter or not.
        {
            char base{'A'};
            char oldCharacter{message[counter]};
            char newCharacter{static_cast<char>(base + (oldCharacter - base + key) % 26)};
            encryptedMessage[counter] = newCharacter;
        }
    }
    return encryptedMessage; // this is a stub
}

std::string decryptShift(const std::string &message, unsigned key)
{
    // Created a new string object here since the string object
    // inside the parameter contains a const, hence it cannot be modified.
    std::string decryptedMessage{message};
    for(int counter{0}; counter < int(message.length()); counter++)
    {
        if(message[counter] != ' ') // // Validating whether the character is a letter or not.
        {
            char base{'A'};
            char oldCharacter{message[counter]};
            char newCharacter{static_cast<char>(base + (oldCharacter - base - key + 26) % 26)};
            decryptedMessage[counter] = newCharacter;
        }
    }
    return decryptedMessage; // this is a stub
}



bool decryptSubstitution(const std::string &message, const std::string & crib, std::string &substitutionMap)
{
    int cribLength{static_cast<int>(crib.length())};
    int messageLength{static_cast<int>(message.length())};
    
    // Iterate through the messages to find potential matches.
    for (int i{0}; i <= messageLength - cribLength; ++i) 
    {
        char cribChar;
        char messageChar;
        substitutionMap = std::string(26, '-');
        std::string messageSubstring{message.substr(i, cribLength)};
        bool match{true};

        for (int pos{0}; pos < cribLength; ++pos)
        {
            cribChar = crib[pos];
            messageChar = messageSubstring[pos];

            // Handle spaces in crib and message.
            if (cribChar == ' ')
            {
                if (messageChar != ' ') 
                {
                    match = false;
                    break;
                }
                continue;
            }

            if (static_cast<int>(messageChar) < 65 || static_cast<int>(messageChar) > 90)
            {
                match = false;
                break;
            }

            if (substitutionMap[cribChar - 'A'] == '-')
            {
                bool foundInSubstitutionMap{false};

                // Check if the message character is already assigned to another crib character.
                for (char k{'A'}; k <= 'Z'; ++k)
                {
                    if (substitutionMap[k - 'A'] == messageChar)
                    {
                        foundInSubstitutionMap = true;
                        break;
                    }
                }

                // Checks if a message character has not been found in
                // substitution map for any crib character.
                if (!foundInSubstitutionMap)
                {
                    substitutionMap[cribChar - 'A'] = messageChar;
                }
                else
                {
                    match = false;
                    break;
                }
            }
            else if (substitutionMap[cribChar - 'A'] != messageChar)
            {
                match = false;
                break;
            }
        }

        // If the crib matches the message, the substitution map is filled with the appropriate characters.
        if (match)
        {
            for (int pos{0}; pos < cribLength; ++pos) 
            {
                cribChar = crib[pos];
                messageChar = messageSubstring[pos];
                if (cribChar != ' ')
                {
                    substitutionMap[cribChar - 'A'] = messageChar;
                }
            }
            return true;
        }
    }
    return false;
}

std::string encryptAffine(const std::string &message, unsigned affineAlpha, unsigned affineBeta)
{
    int messageLength{static_cast<int>(message.length())};
    char base{'A'};
    std::string encryptedMessage;

    // Iterate through the characters of the message
    for (int pos{0}; pos < messageLength; ++pos)
    {   
        if (message[pos] == ' ')
        {
            encryptedMessage += ' ';
            continue;
        }

        // Encryption formula is applied to the character and converting it to a new character.
        int newChar{static_cast<int>((message[pos] - base) * affineAlpha + affineBeta) % 26 + base};
        encryptedMessage += static_cast<char>(newChar);
    }
    return encryptedMessage; // this is a stub
}


// note: this is the ENCRYPTION key, not the decryption key.
// You are guaranteed that affineAlpha is odd, in the range [1,25], and is not 13.  
std::string decryptAffine(const std::string &message, unsigned affineAlpha, unsigned affineBeta)
{
    int messageLength{static_cast<int>(message.length())};
    int inverseOfAlpha{1};
    char base{'A'};
    std::string decryptedMessage;

    // Calculates the modular multiplicative inverse of affineAlpha. 
    while((affineAlpha * inverseOfAlpha) % 26 != 1)
    {
        inverseOfAlpha++;
    }

    // Iterate through the characters of the message.
    for (int pos{0}; pos < messageLength; ++pos)
    {
        if (message[pos] == ' ')
        {
            decryptedMessage += ' ';
            continue;
        }

        // Decryption formula is applied to the character and converting back to the original character.
        int newChar{(static_cast<int>(message[pos] - base - affineBeta) * inverseOfAlpha + 26) % 26 + base};
        decryptedMessage += static_cast<char>(newChar);
    }

    return decryptedMessage; // this is a stub
}
