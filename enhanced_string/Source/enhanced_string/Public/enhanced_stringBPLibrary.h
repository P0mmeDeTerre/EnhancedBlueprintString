// Copyright Ryckbosch Arthur 2024. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenericPlatform/GenericPlatform.h"
#include "enhanced_stringBPLibrary.generated.h"



UENUM(BlueprintType)
enum class EIPv4Class : uint8
{
	EIPv4C_A = 0 UMETA(DisplayName = "Class A"),
	EIPv4C_B = 1 UMETA(DisplayName = "Class B"),
	EIPv4C_C = 2 UMETA(DisplayName = "Class C"),
	EIPv4C_D = 3 UMETA(DisplayName = "Class D"),
	EIPv4C_E = 4 UMETA(DisplayName = "Class E"),
	EIPv4C_All = 5 UMETA(DisplayName = "All Classes")
};


UCLASS()
class ENHANCED_STRING_API  Uenhanced_stringBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:

	Uenhanced_stringBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

	static FString lowerCharacters;
	static FString upperCharacters;
	static FString numericCharacters;
	static FString specialCharacters;
	static TArray<FString> startUrl;

	static FString enhanced_stringRandomString(FString randomCharacters, int length);
	static FString enhanced_stringRemoveHttpHttpsInUrl(FString string);
	static FString enhanced_stringGetUrlPath(FString string);
	static FString enhanced_stringClampString(FString string, int minLength, int maxLength);
	static TArray<FString> enhanced_stringGetSplitedUrl(FString string);
	static TCHAR enhanced_stringGetLowerCharacter(TCHAR character);
	static TCHAR enhanced_stringGetUpperCharacter(TCHAR character);
	static bool enhanced_stringIsNumeric(TCHAR character);
	static bool enhanced_stringIsAlpha(TCHAR character);
	static bool enhanced_stringIsSpecial(TCHAR character);
	static bool enhanced_stringIsUpper(TCHAR character);
	static bool enhanced_stringIsLower(TCHAR character);
	static bool enhanced_stringContainsChar(FString string, TCHAR character);
	static int64 enhanced_stringBinaryToDecimal(FString string);

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Enhanced Blueprint String", ToolTip = "return the lenth of the given string", Keywords = "get string lenght"), Category = "Enhanced Blueprint String")
	static FString test(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get String Lenth", ToolTip = "return the lenth of the given string", Keywords = "get string lenght"), Category = "Enhanced Blueprint String")
	static int enhanced_stringGetstringLength(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is String Index valid", ToolTip = "Check if the index of the string is valid", Keywords = "Is valid string index"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsValidStringIndex(FString string, int index);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Contain SubString In String", ToolTip = "return true if the sub string has been found in the given string", Keywords = "contains substring in string"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringContainsSubStringInString(FString string, FString subString);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Count Sub String In String", ToolTip = "return the number of sub string in the given string", Keywords = "count substring in string"), Category = "Enhanced Blueprint String")
	static int enhanced_stringCountSubStringInString(FString subString, FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Generate Random String", ToolTip = "generate a string that contains a-z, A-Z, 0-1, and all specific characters", Keywords = "generate random string"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGenerateRandomString(int minLenth = 1, int maxLenth = 1);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Generate Custom Random String", ToolTip = "generate a random string with your custom characters in it", Keywords = "generate custom  random string"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGenerateCustomRandomString(FString randomCharacters, int minLenth = 1, int maxLenth = 1);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Generate IPv4", ToolTip = "Generate an IPv4 (does not include 0.0.0.0 and 127.0.0.1)", Keywords = "generata ipv4"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGenerateIPv4(EIPv4Class ipClass);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Generate IPv6", ToolTip = "Generate an IPv6  (does not include ::0 and ::1)", Keywords = "gnerate ipv6"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGenerateIPv6();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Randomize characters in string", ToolTip = "generate a string that contains a-z, A-Z, 0-1, and all specials characters", Keywords = "randomize string"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRandomizeString(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Move Left", ToolTip = "Move all characters to the left starting at index with number of iteration", Keywords = "move left"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringMoveLeft(FString string, int iteration);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Move Right", ToolTip = "Move all characters to the right starting at index with number of iteration", Keywords = "move right"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringMoveRight(FString string, int iteration);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Find Last Char Index", ToolTip = "find the last index of a char in a string. function will always use the first character of the 'character' variable", Keywords = "find last char index"), Category = "Enhanced Blueprint String")
	static int32 enhanced_stringFindLastCharIndex(FString string, FString character);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Find First Char Index", ToolTip = "find the first index of a char in a string. function will always use the first character of the 'character' variable", Keywords = "find first char index"), Category = "Enhanced Blueprint String")
	static int32 enhanced_stringFindFirstCharIndex(FString string, FString character);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Char Array", ToolTip = "get a array of chars with all character's string", Keywords = "get chars array"), Category = "Enhanced Blueprint String")
	static TArray<FString> enhanced_stringGetCharArray(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Insert String At", ToolTip = "insert a string in a string at index", Keywords = "insert at"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringInsertStringAt(FString string, FString insertString, int index);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get String After Char", ToolTip = "return a string part after the n (count) given char. If count is bigger than char number, it will use the last found char of the string", Keywords = "get after char"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetStringAfterChar(FString string, FString character, int count);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get String Before Char", ToolTip = "return a string part before the n (count) given char. If count is bigger than char number, it will use the last found char of the string", Keywords = "get before char"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetStringBeforeChar(FString string, FString character, int count);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get String After First Char", ToolTip = "return a string part after the first given char", Keywords = "get after first char"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetStringAfterFirstChar(FString string, FString character);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get String Before First Char", ToolTip = "return a string part before the first given char", Keywords = "get before first char"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetStringBeforeFirstChar(FString string, FString character);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get String After Last Char", ToolTip = "return a string part after the last given char", Keywords = "get after last char"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetStringAfterLastChar(FString string, FString character);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get String Before Last Char", ToolTip = "return a string part before the last given char", Keywords = "get before last char"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetStringBeforeLastChar(FString string, FString character);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get URL Sub Domain", ToolTip = "Return the subdomain part of a URL", Keywords = "get url subdomain"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetUrlSubDomain(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get URL TLD", ToolTip = "Return the top-level domain (TLD) of a URL", Keywords = "get url tld"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetUrlTLD(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get URL Domain", ToolTip = "Return the domain part of a URL", Keywords = "get url domain"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetUrlDomain(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get DateTime Date As String", ToolTip = "Return the date portion of a dateTime as a string", Keywords = "get datetime date string"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetDateTimeDateAsString(FDateTime dateTime);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get DateTime Time As String", ToolTip = "Return the time portion of a dateTime as a string", Keywords = "get datetime time string"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetDateTimeTimeAsString(FDateTime dateTime);


	// remove

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove At", ToolTip = "remove character in a string at index", Keywords = "remove at"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveAt(FString string, int index);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove Spaces", ToolTip = "remove all spaces in a string", Keywords = "remove spaces"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveSpaces(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove Numerics", ToolTip = "remove all numerics in a string", Keywords = "remove numerics"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveNumerics(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove Alphas", ToolTip = "remove all Alphas in a string", Keywords = "remove alphas"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveAlphas(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove Specials", ToolTip = "remove all specials characters in a string", Keywords = "remove specials"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveSpecials(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove Upper", ToolTip = "remove all upper characters in a string", Keywords = "remove upper"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveUpper(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove Lower", ToolTip = "remove all lower characters in a string", Keywords = "remove lower"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveLower(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove Multiple Spaces", ToolTip = "remove multiple spaces in a string. ('this    is a   string' --> 'this is a string')", Keywords = "remove multiple spaces"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveMultipleSpaces(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove Chars", ToolTip = "remove any given characters in a string. Each char of the given characters will be removed from the given string", Keywords = "remove chars"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveChars(FString string, FString characters);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Trim Start", ToolTip = "remove all spaces at the start of the string", Keywords = "trim start"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringTrimStart(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Trim End", ToolTip = "remove all spaces at the end of the string", Keywords = "trim end"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringTrimEnd(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Trim Start End", ToolTip = "remove all spaces at the start and at the end of the string", Keywords = "trim start end"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringTrimStartEnd(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Trim Quotes", ToolTip = "Remove first and last characters if they are quotes", Keywords = "trim quotes"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringTrimQuotes(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Split By Separator", ToolTip = "split a string by a separator. Return an array of string", Keywords = "split separator"), Category = "Enhanced Blueprint String")
	static TArray<FString> enhanced_stringSplitBySeparator(FString string, FString separator);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove From Start", ToolTip = "Removes the text from the start of the string if it exists.", Keywords = "remove start"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveFromStart(FString string, FString inPrefix);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove From End", ToolTip = "Removes the text from the end of the string if it exists.", Keywords = "remove end"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveFromEnd(FString string, FString inPrefix);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove From Start And End", ToolTip = "Removes the text from the start end the end of the string if it exists.", Keywords = "remove start end"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveFromStartAndEnd(FString string, FString inPrefix);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove String", ToolTip = "Return a string with the specified substring removed", Keywords = "remove substring"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveString(FString string, FString subString);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove Strings", ToolTip = "Return a string with the specified substrings removed", Keywords = "remove substrings"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringRemoveStrings(FString string, TArray<FString> subStrings);

	//v1.3
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Remove Duplicates from String Array", Keywords = "Remove Duplicates String Array Unique"), Category = "Enhanced Blueprint String")
	static TArray<FString> enhanced_stringRemoveDuplicatesFromStringArray(TArray<FString> stringArray);



	// string modification 

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "To Lower String", ToolTip = "return a string with only lowercase characters", Keywords = "lower"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringToLower(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "To Upper String", ToolTip = "return a string with only uppercase characters", Keywords = "Upper"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringToUpper(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Invert String", ToolTip = "return a string with invert characters order", Keywords = "invert string"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringInvertString(FString string);

	// string cases 

	// First Alpha of each words are in lower case exept the first one, spaces are deleted
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "To Camel Case", ToolTip = "Convert string into a Came Case string format \n First character of each words are in lower case exept the first one, spaces are deleted", Keywords = "camel case"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringToCamelCase(FString string);

	// First Alpha of each words are in lower case, spaces are deleted
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "To Pascal Case", ToolTip = "Convert string into a Pascal Case string format \n First character of each words are in lower case, spaces are deleted", Keywords = "pascal case"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringToPascalCase(FString string);

	// spaces between words are replaced with underscores. All Alphas are in lower case
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "To Snake Case", ToolTip = "Convert string into a Snake Case string format \n spaces between words are replaced with underscores ( _ ). All characters are in lower case", Keywords = "snake case"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringToSnakeCase(FString string);

	// spaces between words are replaced with dashes ( - ). All characters are in lower case
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "To Kebab Case", ToolTip = "Convert string into a Kebab Case string format \n spaces between words are replaced with dashes ( - ). All characters are in lower case", Keywords = "kebab case"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringToKebabCase(FString string);

	// First Alpha is in upper case and other ones are in lower case
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "To Title Case", ToolTip = "Convert string into a Title Case string format \n First character is in lower case and other ones are in lower case", Keywords = "title case"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringToTitleCase(FString string);

	//Upper characters will become lower characters and low characters will become upper characters
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "To Invert Case", ToolTip = "Convert string into a Invert Case string format \n Upper characters will become lower characters and low characters will become upper characters", Keywords = "invert case"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringInvertCase(FString string);

	// Characters will be alterned between upper and lower ( depending on the first character cases )
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "To Alternate Case", ToolTip = "Convert string into a Alternate Case string format \n Characters will be alterned between upper and lower ( depending on the first character cases )", Keywords = "alternate case"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringAlternateCase(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Capitalize Words", ToolTip = "Return the string with each first letter of the word capitalized. ex hEllO WorLd --> Hello World", Keywords = "Capitalize Words"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringCapitalizeWords(FString string, FString separator);

	
	// Convertion
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert String To Bool", ToolTip = "if the string does not contains a value that can be convert into a boolean value the fonction will be return false. \n acceptable value ({1 | 0}, {true | false}) ", Keywords = "convert string bool"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringConvertStringIntoBool(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert String To Color", ToolTip = "Convert string to string", Keywords = "convert string color"), Category = "Enhanced Blueprint String")
	static FColor enhanced_stringConvertStringToColor(FString string, FString separator);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert Color To String", ToolTip = "Convert color to string", Keywords = "convert color string"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringConvertColorToString(FColor color);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert String To Linear Color", ToolTip = "convert string linear color", Keywords = ""), Category = "Enhanced Blueprint String")
	static FLinearColor enhanced_stringConvertStringToLinearColor(FString string, FString separator);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert String To Datetime", ToolTip = "return a datetime based on string", Keywords = "convert string datetime"), Category = "Enhanced Blueprint String")
	static FDateTime enhanced_stringConvertStringToDatetime(FString string, FString separator);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert String To Rotator", ToolTip = "return a rotator based on string sapces and given separator will be removed automaticly. If no separator was given, space will be chose automaticly", Keywords = "convert string rotator"), Category = "Enhanced Blueprint String")
	static FRotator enhanced_stringConvertStringToRotator(FString string, FString separator);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert String To 3dVector", ToolTip = "return a 3d vector based on string, sapces and given separator will be removed automaticly. If no separator was given, space will be chose automaticly", Keywords = "convert string 3d vector"), Category = "Enhanced Blueprint String")
	static FVector enhanced_stringConvertStringTo3dVector(FString string, FString separator);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert String To 2dVector", ToolTip = "return a 2d vector based on string, sapces and given separator will be removed automaticly. If no separator was given, space will be chose automaticly", Keywords = "convert string 2d vector"), Category = "Enhanced Blueprint String")
	static FVector2D enhanced_stringConvertStringTo2dVector(FString string, FString separator);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert Binary String To Int", ToolTip = "Convert a binary string to int ( return 0 if the conversion failed)", Keywords = "convert binary string int"), Category = "Enhanced Blueprint String")
	static int64 enhanced_stringConvertBinaryStringToInt(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert Int To Binary String", ToolTip = "Convert an int to a binary string", Keywords = "convert int binary"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringConvertIntToBinaryString(int32 value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert Custom Base String To Int", ToolTip = "Convert a number string with a custom base to int ( return 0 if conversion failed )", Keywords = "convert custom base int"), Category = "Enhanced Blueprint String")
	static int64 enhanced_stringConvertCustomBaseStringToInt(FString string, int32 base);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert Hexadecimal String To Int", ToolTip = "Convert a hexadecimal string to int (return 0 if conversion failed )", Keywords = "convert hexadecimal string int"), Category = "Enhanced Blueprint String")
	static int64 enhanced_stringConvertHexadecimalStringToInt(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert Octal String To Int", ToolTip = "Convert an octal string to int (return 0 if conversion failed )", Keywords = "convert octal string int"), Category = "Enhanced Blueprint String")
	static int64 enhanced_stringConvertOctalStringToInt(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert Int To Hexadecimal String", ToolTip = "Convert an int to a hexadecimal string", Keywords = "convert int hexadecimal"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringConvertIntToHexadecimalString(int32 value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert Int To Octal String", ToolTip = "Convert an int to an octal string", Keywords = "convert int otcal"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringConvertIntToOctalString(int32 value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert Int To Custom Base String", ToolTip = "Convert an int to a number string with a custom base", Keywords = "convert int custom base"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringConvertIntToCustomBaseString(int32 value, int32 base);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Convert Date Time To String", ToolTip = "Convert a dateTime to a string", Keywords = "convert datetime"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringConvertDateTimeToString(FDateTime datetime);

	
	// boolean
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is String In String Array", ToolTip = "Return true if the string is found in the array of strings", Keywords = "is string string array"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsStringInStringArray(FString string, TArray<FString> stringArray);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Are Numerics", ToolTip = "return true if all elements of the string are numerics ", Keywords = "are numerics"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringAreNumerics(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Are Alphas", ToolTip = "return true if all elements of the string are Alphas ", Keywords = "are alphas"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringAreAlphas(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Are Specials", ToolTip = "return true if all elements of the string are specials characters ", Keywords = "are specials"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringAreSpecials(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Are Uppers", ToolTip = "return true if all elements of the string are upper characters ", Keywords = "are uppers"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringAreUppers(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Are Lowers", ToolTip = "return true if all elements of the string are lower characters ", Keywords = "are lowers"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringAreLowers(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Contains Numeric", ToolTip = "return true if there is a numeric character in the given string", Keywords = "contains numeric character"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringContainsNumeric(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Contains Alpha", ToolTip = "return true if there is a Alpha in the given string", Keywords = "contains alpha character"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringContainsAlpha(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Contains Special", ToolTip = "return true if there is a special character in the given string", Keywords = "contains sepcial character"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringContainsSpecial(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Contains Upper", ToolTip = "return true if there is an upper character in the given string", Keywords = "contain upper character"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringContainsUpper(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Contains Lower", ToolTip = "return true if there is an lower character in the given string", Keywords = "contains lower character"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringContainsLower(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Contains Chars", ToolTip = "return true if any given characters was found ", Keywords = "contains chars"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringContainsChars(FString string, FString characters);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "String Array Contains SubString", ToolTip = "Return true if the substring is found in the array", Keywords = "String array subString"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringStringArrayContainsSubString(TArray<FString> stringArray, FString subString);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is Email Format", ToolTip = "Check if the string is in the correct email format \n error code \n 0 no error \n 1 contains space \n 2 not allowed character \n 3 less or more than 1 '.' \n 4 less or more than 1 '@' \n 5 wrong '@' location \n 6 wrong '.' location", Keywords = "is email"), Category = "Enhanced Blueprint String")
	static int32 enhanced_stringIsEmailFormat(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is Email Domain Format", ToolTip = "check if the string is in the correct email format and contains given domains", Keywords = "contains email domains"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsEmailDomainFormat(FString string, TArray<FString> domains);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is URL Format", ToolTip = "Check if a string is in the correct URL format \n error code \n 0 no error \n 1 no 'http://' or 'https://' \n 2 less than 3 sections ( separate by '.')", Keywords = "is url"), Category = "Enhanced Blueprint String")
	static int32 enhanced_stringIsUrlFormat(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is URL TLD Format", ToolTip = "Return true if the url has the TLD listed in the given array", Keywords = "is url tld"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsUrlTLDFormat(FString string, TArray<FString> TLD);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is URL Domain Format", ToolTip = "Return true if the url has the TLD listed in the given array", Keywords = "is url domain"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsUrlDomainFormat(FString string, TArray<FString> domains);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is URL Subdomain Format", ToolTip = "Return true if the url has the subdomain listed in the given array", Keywords = "is url subdomain"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsUrlSubdomainFormat(FString string, TArray<FString> subDomains);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is URL Domain And Subdomain Format", ToolTip = "Return true if the url has the domain and subdomain listed in the given arrays", Keywords = "is url subdomain domain"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsUrlDomainAndSubdomainFormat(FString string, TArray<FString> domains, TArray<FString> subDomains);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get URL Path As String", ToolTip = "Get url path as string", Keywords = "get url path"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringGetUrlPathAsString(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get URL Path As String Array", ToolTip = "Get url path as string array", Keywords = "get url path array"), Category = "Enhanced Blueprint String")
	static TArray<FString> enhanced_stringGetUrlPathAsStringArray(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is IPv4 Format", ToolTip = "Return true if the given string is an IPv4", Keywords = "is ipv4"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsIPv4Format(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is IPv6 Format", ToolTip = "Return true if the given string is an IPv6", Keywords = "is ipv6"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsIPv6Format(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is Hexadecimal Format", ToolTip = "Return true if the given string is a hexadecimal number", Keywords = "is hexadecimal"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsHexadecimalFormat(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is Binary Format", ToolTip = "Return true if the given string is a binary number", Keywords = "is binary"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsBinaryFormat(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is Octal Format", ToolTip = "Return true if the given string is an octal number", Keywords = "is octal"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsOctalFormat(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is File Format", ToolTip = "Return true if the file has a given extension", Keywords = "is file extension"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsFileFormat(FString string, TArray<FString> extensions);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is Image Format", ToolTip = "Return true if the file has an image extension", Keywords = "is image"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsImageFormat(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is Video Format", ToolTip = "Return true if the file has a video extension", Keywords = "is video"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsVideoFormat(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is Audio Format", ToolTip = "Return true if the file has an audio extension", Keywords = "is audio"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsAudioFormat(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is URL Http", ToolTip = "Return true if the string represents an HTTP URL", Keywords = "is url http"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsUrlHttp(FString string);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is URL Https", ToolTip = "Return true if the string represents an HTTPS URL", Keywords = "is url https"), Category = "Enhanced Blueprint String")
	static bool enhanced_stringIsUrlHttps(FString string);

	// Set
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set DateTime Day", ToolTip = "Set the day of a dateTime", Keywords = "set day datetime"), Category = "Enhanced Blueprint String")
	static FDateTime enhanced_stringSetDateTimeDay(FDateTime dateTime, int day = 1);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set DateTime Year", ToolTip = "Set the year of a dateTime", Keywords = "set year datetime"), Category = "Enhanced Blueprint String")
	static FDateTime enhanced_stringSetDateTimeYear(FDateTime dateTime, int year = 1);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set DateTime Month", ToolTip = "Set the month of a dateTime", Keywords = "set month datetime"), Category = "Enhanced Blueprint String")
	static FDateTime enhanced_stringSetDateTimeMonth(FDateTime dateTime, int month = 1);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set DateTime Date", ToolTip = "Set the date (day, month and year) of a dateTime", Keywords = "set day month year datetime"), Category = "Enhanced Blueprint String")
	static FDateTime enhanced_stringSetDateTimeDate(FDateTime dateTime, int year = 1, int month = 1, int day = 1);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set DateTime Hour", ToolTip = "Set the hour of a dateTime", Keywords = "set hour datetime"), Category = "Enhanced Blueprint String")
	static FDateTime enhanced_stringSetDateTimeHour(FDateTime dateTime, int hour = 0);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set DateTime Minute", ToolTip = "Set the minute of a dateTime", Keywords = "set minute datetime"), Category = "Enhanced Blueprint String")
	static FDateTime enhanced_stringSetDateTimeMinute(FDateTime dateTime, int minute = 0);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set DateTime Second", ToolTip = "Set the second of a dateTime", Keywords = "set second datetime"), Category = "Enhanced Blueprint String")
	static FDateTime enhanced_stringSetDateTimeSecond(FDateTime dateTime, int second = 0);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set DateTime Millisecond", ToolTip = "Set the millisecond of a dateTime", Keywords = "set millisecond datetime"), Category = "Enhanced Blueprint String")
	static FDateTime enhanced_stringSetDateTimeMillisecond(FDateTime dateTime, int millisecond = 0);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set DateTime Time", ToolTip = "Set the time (hour, minute, second and millisecond) of a dateTime", Keywords = "set hour minute second millisecond datetime"), Category = "Enhanced Blueprint String")
	static FDateTime enhanced_stringSetDateTimeTime(FDateTime dateTime, int hour = 0, int minute = 0, int second = 0, int millisecond = 0);


	// ORDER v1.3
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Order String Array By Lenght", Keywords = "Order String Array Lenght"), Category = "Enhanced Blueprint String")
	static TArray<FString> enhanced_stringOrderStringArrayByLength(TArray<FString> stringArray, bool ascending = true);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Order String Array By Alphanumeric", Keywords = "Order String Array "), Category = "Enhanced Blueprint String")
	static TArray<FString> enhanced_stringOrderStringArrayByAlphanumeric(TArray<FString> stringArray, bool ascending = true);

	// FIND v1.3
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Find Longest String in Array", Keywords = "Find Longest String Array"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringFindLongestStringInArray(TArray<FString> stringArray);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Find Shortest String in Array", Keywords = "Find Shortest String Array"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringFindShortestStringInArray(TArray<FString> stringArray);

	// COUNT v1.3
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Count Occurrences of Substring in Array", Keywords = "Count Substring Occurrences String Array"), Category = "Enhanced Blueprint String")
	static int32 enhanced_stringCountOccurrencesOfSubstringInArray(TArray<FString> stringArray, FString substring);

	// CLAMP v1.3

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Clamp String By Length", Keywords = "Clamp String Length"), Category = "Enhanced Blueprint String")
	static FString enhanced_stringClampStringByLength(FString string, int32 minLength = 0, int32 maxLength = 1);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Clamp String Array By Length", Keywords = "Clamp String Array Length"), Category = "Enhanced Blueprint String")
	static TArray<FString> enhanced_stringClampStringArrayByLength(TArray<FString> stringArray, int32 minLength = 0, int32 maxLength = 1);

	// FILTER v1.3
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Filter String Array By Length", Keywords = "Filter String Array Length"), Category = "Enhanced Blueprint String")
	static TArray<FString> enhanced_stringFilterStringArrayByLength(TArray<FString> stringArray, int32 minLength = 0, int32 maxLength = 1);



};