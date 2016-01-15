RhymeBot-

RhymeBot will be a data structure that can efficiently find rhymes and alliterations for given words.  
It will be utilizing the The CMU Pronouncing Dictionary for word pronunciation and WordNet from Princeton for the parts of speech. 


Inserting Words

There are two functions that will be used to add information about words into the RhymeBots data structures (dictionary). This function is used to insert a new word along with its pronunciation.

void insertWithPronunciation(string word, vector<Sound> pronunciation);

The pronunciation is given as a vector of instances of the Sound class. The Sound class stores the pronunciation information for each sound that has been extracted from the CMU dictionary.  The most important information about a sound will be whether it is a vowel or not.


void addPartOfSpeech(string word, PART_OF_SPEECH partOfSpeech);

This will add a part of speech to word if it has been added to the dictionary previously. If word is not already in RhymeBot, then this function should not do anything (don’t need to store words that have a known part of speech but no known pronunciation). The part of speech can be viewed as extra information that may or may not be provided for each word, but the pronunciation is required for any word stored by RhymeBot.



1. Count Syllables 

 This function will count the number of syllables in the given word.

int countSyllables(string word);

The number of syllables in a word is equivalent to the number of vowel sounds it contains. 


2. Count Rhyming Syllables 

count the number of rhyming syllables in two words.

int rhymingSyllables(string word1, string word2);

Two words are said to rhyme if their suffixes upto and including the last vowel have identical sounds. The number of rhyming syllables is the number of vowel sounds in the maximum size suffix that has identical sounds in the two words. If the two words do not rhyme, return 0.


3. Count Alliterating Sounds 

counts the size of the alliteration formed between two words.

int alliterationSounds(string word1, string word2);

Two words form an alliteration if they begin with the same sound. We will define the size of an alliteration as the maximum number of matching sounds in the prefixes of the two words. Note that when computing the size of an alliteration we will count all sounds in the matching prefix, but the size of a rhyme will be the number of vowel sounds (syllables) in the matching sounds of the suffixes.

Finding Rhymes and Alliterations 

1. Get All Rhymes 

vector<string>* getAllRhymes(string word);

This function will query the data structures used to store the words that have been added with insertWithPronunciation and return all known words that rhyme at least one syllable with the given word. The vector can store the words in any order. If no rhyming words are found, or if the given word in not in the dictionary, an empty vector will be returned.


2. Acquire All Alliterations 


vector<string>* getAllAlliterations(string word);

This will return all known words that form an alliteration of at least 1 sound with the given word. If no alliterations are found, or if the given word in not in the dictionary, an empty vector will be returned.

Finding Best Rhyme and Alliteration

1. Find Best Rhyme

 Given a word and some criteria we will return the “best” rhyming word. Some of these functions will make use of the parts of speech that were added to some of the words in the dictionary. The best rhyme will be the word that rhymes the most syllables with the given word. If there is a tie in any of the functions in this section, any of the tieing words can be returned.

string findBestRhyme(int numberOfSyllables, string rhymesWith);
string findBestRhyme(PART_OF_SPEECH, string rhymesWith);
string findBestRhyme(int numberOfSyllables, PART_OF_SPEECH, string rhymesWith);

If no word if found that fits all the criteria, or if the given word is not in the dictionary, return “”.


2. Find Best Alliteration 

 The best alliteration is defined as the word with the most number of matching sounds that form an alliteration with the given word.

string findBestAlliteration(int numberOfSyllables, string alliterationWith);
string findBestAlliteration(PART_OF_SPEECH, string alliterationWith);
string findBestAlliteration(int numberOfSyllables, PART_OF_SPEECH, string alliterationWith);

If no word if found that fits all the criteria, or if the given word is not in the dictionary, return “”.




