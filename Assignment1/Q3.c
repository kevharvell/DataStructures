/* CS261- Assignment 1 - Q.3*/
/* Name: Kevin Harvell
 * Date: 7/6/2018
 * Solution description: This program takes a string input from the user,
 * converts in into only alpha characters with '_' separating words, then
 * passes it to the camelCase function which turns it into camelCase.
 */

#include <stdio.h>
#include <stdlib.h>



char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
  ch -= 32; 
  return ch;
}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/                          
  ch += 32;
  return ch;
}

int stringLength(char s[]) {
   /*Return the length of the string*/
	int i = 0;
	int length = 0;
	while(s[i] != '\0') {
	  length++;
	  i++;
	}
	return length;
}


void camelCase(char* word){
	/*Convert to camelCase*/
	// Iterate through word looking for '_' which will cue when to 
	// remove and make the next letter capitalized.
	for(int i = 0; i < stringLength(word); i++) {
		// If the character is a '_'
		if(word[i] == '_') {
		  // Make letter after '_' capitalized
		  word[i] = toUpperCase(word[i+1]);
		  // Reposition the rest of the letters
		  for(int j = i + 1; j < stringLength(word); j++) {
		  	word[j] = word[j+1];
		  }
		}
	}
}

int main(){
	char str[100];
	char newStr[100];

	/*Read the string from the keyboard*/
	printf("Please enter a string to convert to camelCase: ");	
	scanf("%99[^\n]", str);
	
	// Loop through string input looking for capital letters to lowercase,
	// and alpha characters are transferred to newStr. The non-alpha characters
	// are ignored except for putting a single '_' into the newStr array
	int j = 0;
	for(int i = 0; i < stringLength(str); i++) {
	  if(str[i] >= 'A' && str[i] <= 'Z') {
	  	newStr[j] = toLowerCase(str[i]);
		j++;
	  }	  
	  else if(str[i] >= 'a' && str[i] <= 'z') {
		newStr[j] = str[i];
		j++;
	  } else if(i != 0 && j != 0 && newStr[j - 1] != '_') {
		newStr[j] = '_';
		j++;
	  }
	}

	// The above code will leave a '_' at the end. The following code lops the '_' off
	if(newStr[stringLength(newStr) - 1] == '_') {
		newStr[stringLength(newStr) - 1] = newStr[stringLength(newStr)];
	}

	/*Call camelCase*/
	camelCase(&newStr);
	
	/*Print the new string*/
	printf("Old string: %s\n", str);
	printf("New string: %s\n", newStr);
		
	return 0;
}

