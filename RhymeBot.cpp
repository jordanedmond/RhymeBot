#include "RhymeBot.h"
#include "Sound.h"


//#include "Sound.h"
//#include "Sound.cpp"


/** Inserting Words **/

void RhymeBot::insertWithPronunciation(string word, vector<Sound> pronunciation){
    // TODO
	mydic.insert(make_pair(word,pronunciation));
	if (dict.count(word)==0){
			dict[word].isvoid = -99999;
			dict[word].spelling = pronunciation;

			}
		else{

		}
    // The following lines should be removed. They are here to show what is being added to you data structures
//    cout << word << ":*** ";
//    cout<<mydic["word"];
//    int coutVowel;
//    bool booo;
//    for(int i=0; i<12; i++){
////    	booo=pronunciation.at(i).isVowel();
//        cout << mydic[word].at(0)<< "what is this@@@@@@@@@@";
//    }
//    cout << endl;

}







void RhymeBot::addPartOfSpeech(string word, PART_OF_SPEECH partOfSpeech){
    // TODO
//	cout << word << ": " << partOfSpeech << endl;
	if (mydic.count(word)==1){
	mypar.insert(make_pair(word,partOfSpeech));
}


	if (dict.count(word)==1)
			{
				dict[word].isvoid = partOfSpeech;

			}
		else{

		}
    // The following line should be removed. They are here to show what is being added to you data structures




//    cout << word << ": " << mypar[word] << endl;

}

//
////case 0:
//            return "adjective";
//        case 1:
//            return "adverb";
//        case 2:
//            return "noun";
//        case 3:
//            return "sense";
//        case 4:
//            return "verb";












































/** Helper Functions **/

// returns the number of syllables in word
int RhymeBot::countSyllables(string word){

	int HowManySyllables = -1;
	vector<Sound> ok= mydic[word] ;
	for(int i=0; i<ok.size();i++){
		if(ok.at(i).isVowel()==true){
			HowManySyllables++;
		}

	}
    return HowManySyllables +1 ;
}

// returns the number of rhyming syllables in the two words. This is defined as the number of vowel sounds in the
//  largest rhyming suffix.
//
// Words are considered a rhyme if they have the same last vowel sound as well as the same sounds following
//  the last vowel. Note: These are syllabic rhymes since the matching vowels might not both be stressed
int RhymeBot::rhymingSyllables(string word1, string word2){
	if(mydic.find(word1) == mydic.end()) return 0;
	else if(mydic.find(word2) == mydic.end()) return 0;
	int rhymes = 0;
	int i = mydic[word1].size() - 1, j = mydic[word2].size() - 1;
	while(i > -1 && j > -1){
		if(mydic[word1][i] != mydic[word2][j]) return rhymes;
		else if(mydic[word1][i].isVowel()) rhymes = rhymes + 1;
		--i, --j;
	}
	return rhymes;
}

// returns the number of identical sounds in the largest matching prefix of the two words.
//
// Words are considered an alliteration if they have the same first sound
int RhymeBot::alliterationSounds(string word1, string word2){
    // TODO
	int alli=0;
	int allitotal =0;
	int start;
	vector<Sound> ok= mydic[word1] ;
	vector<Sound> ok2= mydic[word2] ;
	if (ok.at(0)!=ok2.at(0)){
			return 0 ;
		}



	int smallerSize = ok.size();
	if(smallerSize>ok2.size()){
		smallerSize =ok2.size();
	}


	for(int i =0; i<smallerSize;i++){
	if (ok.at(i)==ok2.at(i)){
		alli++;
	}
	else{
		alli=0;
	}

	if (allitotal <alli){
		allitotal = alli;
	}
	else{
			alli=0;
		}
	}

    return allitotal;
}


/** Search for Rhymes and Alliterations **/

// returns all words that rhyme at least 1 syllable with the input word
// returns the empty vector if no rhymes are found or if the given word is not in the dictionary
vector<string>* RhymeBot::getAllRhymes(string word){
    vector<string>* rhymingWords = new vector<string>;
    // TODO
    for (std::map<string,vector<Sound>>::iterator it=mydic.begin(); it!=mydic.end(); ++it){
    		if(rhymingSyllables(word,it->first)!=0){
    			rhymingWords->push_back(it->first);
    		}
    	}




    return rhymingWords;
}

// returns all words that form an alliteration of at least 1 sound with the input word
// returns the empty vector if no rhymes are found or the given word is not known
vector<string>* RhymeBot::getAllAlliterations(string word){
	 vector<string>* alliterationWords = new vector<string>;

	for (std::map<string,vector<Sound>>::iterator it=mydic.begin(); it!=mydic.end(); ++it){
		if(alliterationSounds(word,it->first)>0){

			alliterationWords->push_back(it->first);
		}
	}

    return alliterationWords;
}




/** Finding the Perfect Word **/

// returns the best word with the specified number of syllables and part of speech that rhymes with the given word.
// Best is defined by the maximum number of rhyming syllables.
string RhymeBot::findBestRhyme(int numberOfSyllables, string rhymesWith){
	string current=" ";
		int longest =0;
		for (std::map<string,vector<Sound>>::iterator it=mydic.begin(); it!=mydic.end(); ++it){
			if ((countSyllables(it->first))==numberOfSyllables){

			string temp = it->first;
			int ok=	rhymingSyllables(temp,rhymesWith);
			if(ok>longest){
				longest =ok;
				current = temp;
			}

			}
			}
	    return current;
	}

string RhymeBot::findBestRhyme(PART_OF_SPEECH s , string rhymesWith){
	string current = "";
	int longest = 0;
	for (std::map<string,Dict>::iterator it=dict.begin(); it!=dict.end(); ++it){
		if (it->second.isvoid == s)
		{
			int ok= rhymingSyllables(it->first, rhymesWith);
			if (ok > longest)
			{
				longest = ok;
				current = it->first;
			}
		}
	}
	return current;

}
string RhymeBot::findBestRhyme(int numberOfSyllables, PART_OF_SPEECH s, string rhymesWith){
	string current="";
	int longest = 0;

	for (std::map<string,Dict>::iterator it=dict.begin(); it!=dict.end(); ++it){
		if (it->second.isvoid == s &&countSyllables(it->first)==numberOfSyllables)
		{
			int ok= rhymingSyllables(it->first, rhymesWith);
			if (ok > longest)
			{
				longest = ok;
				current = it->first;
			}
		}
	}
	return current;

}


// returns the best word with the specified number of syllables and part of speech that forms an alliteration with
// the given word. Best is defined by the number of maximum number of alliterating sounds.
string RhymeBot::findBestAlliteration(int numberOfSyllables, string alliterationWith){
	string current="";
	int longest =0;
	for (std::map<string,vector<Sound>>::iterator it=mydic.begin(); it!=mydic.end(); ++it){
		if ((countSyllables(it->first))==numberOfSyllables){

		string temp = it->first;
		int ok=	alliterationSounds(temp,alliterationWith);
		if(ok>longest){
			longest =ok;
			current = temp;
		}

		}
		}
    return current;
}
string RhymeBot::findBestAlliteration(PART_OF_SPEECH s , string alliterationWith){
	string current="";
	int longest =0;
        vector<string>*okkk=getAllAlliterations_Part(alliterationWith);

        for (int i =0;i<okkk->size();i++){
        	int ok;
        	if (alliterationWith!=okkk->at(i)&&mypar[okkk->at(i)]==s){
        	ok=	alliterationSounds(alliterationWith,okkk->at(i));
        	if(ok>longest&&mypar[okkk->at(i)]==s){
        				longest =ok;
        				current =okkk->at(i) ;
        			}
        	}
        }

    return current;
}



string RhymeBot::findBestAlliteration(int numberOfSyllables, PART_OF_SPEECH s, string alliterationWith){
	string current="";
	int longest =0;
        vector<string>*okkk=getAllAlliterations_Part(alliterationWith);

        for (int i =0;i<okkk->size();i++){
        	int ok;
        	if (alliterationWith!=okkk->at(i)&&mypar[okkk->at(i)]==s&&countSyllables(okkk->at(i))==numberOfSyllables){
        	ok=	alliterationSounds(alliterationWith,okkk->at(i));
        	if(ok>longest&&mypar[okkk->at(i)]==s){
        				longest =ok;
        				current =okkk->at(i) ;
        			}
        	}
        }

    return current;


	}

// Combine findBestRhyme and findBestAlliteration. Best is defined by the sum of the number of rhyming syllables
//  and the number of alliterating sounds.
string RhymeBot::findPerfectWord(int numberOfSyllables, PART_OF_SPEECH s, string rhymesWith, string alliterationWith){
    // TODO
//	vector<string >* alla =getAllAlliterations(alliterationWith);
//	vector<string >* allr= getAllRhymes(rhymesWith);
//    for(int i =0;i<alla->size();i++){
//    	for (int j =0;j<allr->size();j++){
//
//    	}
//    }

//    string besta = "";
//
//
//    string bestr = "";
//
//
//
//	besta = findBestAlliteration(numberOfSyllables,s,alliterationWith);
//	bestr = findBestRhyme(numberOfSyllables,s,rhymesWith);
//










    return "";
}

vector<string>* RhymeBot::getAllAlliterations_Part(string word){
	 vector<string>* alliterationWords = new vector<string>;

	for (std::map<string,vector<Sound>>::iterator it=mydic.begin(); it!=mydic.end(); ++it){
		if(alliterationSounds(word,it->first)>0&&mypar.count(it->first)!=0){

			alliterationWords->push_back(it->first);
		}
	}

    return alliterationWords;
}



vector<string>* RhymeBot::getAllRhymes_Part(string word){
    vector<string>* rhymingWords = new vector<string>;
    // TODO
    for (std::map<string,vector<Sound>>::iterator it=mydic.begin(); it!=mydic.end(); ++it){
    		if(rhymingSyllables(word,it->first)>=0&&mypar.count(it->first)!=0){
    			rhymingWords->push_back(it->first);
    		}
    	}




    return rhymingWords;
}


