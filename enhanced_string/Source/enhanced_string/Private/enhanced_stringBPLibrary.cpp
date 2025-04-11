// Copyright Ryckbosch Arthur 2024. All Rights Reserved.

#include "enhanced_stringBPLibrary.h"
#include "Internationalization/Regex.h"
#include "enhanced_string.h"
#include "WorldPartition/ContentBundle/ContentBundleLog.h"


FString Uenhanced_stringBPLibrary::lowerCharacters = "abcdefghijklmnopqrstuvwxyz";
FString Uenhanced_stringBPLibrary::upperCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
FString Uenhanced_stringBPLibrary::numericCharacters = "0123456789";
FString Uenhanced_stringBPLibrary::specialCharacters = "!@#$%^&*()_-+=<>?";
TArray<FString> Uenhanced_stringBPLibrary::startUrl = { "http://", "https://" };

FString Uenhanced_stringBPLibrary::enhanced_stringRandomString(FString randomCharacters, int lenth)
{
	FString randomString;
	int randomCharactersLenth = enhanced_stringGetstringLength(randomCharacters);

	for (int i = 0; i < lenth; i++)
	{
		randomString += randomCharacters[FMath::RandRange(0, randomCharactersLenth - 1)];
	}

	return randomString;
}

TArray<FString> Uenhanced_stringBPLibrary::enhanced_stringGetSplitedUrl(FString string)
{
	FString newString;
	TArray<FString> splitedString;

	newString = enhanced_stringRemoveHttpHttpsInUrl(string);

	splitedString = enhanced_stringSplitBySeparator(newString, ".");

	return splitedString;
}

TCHAR Uenhanced_stringBPLibrary::enhanced_stringGetLowerCharacter(TCHAR character)
{
	return FChar::ToLower(character);
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveHttpHttpsInUrl(FString string)
{
	FString newString;
	FString empty = "";

	newString = string;
	newString = newString.Replace(*startUrl[0], *empty, ESearchCase::IgnoreCase);
	newString = newString.Replace(*startUrl[1], *empty, ESearchCase::IgnoreCase);

	return newString;
}

TCHAR Uenhanced_stringBPLibrary::enhanced_stringGetUpperCharacter(TCHAR character)
{
	return FChar::ToUpper(character);
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetUrlPath(FString string)
{
	FString newString;
	FString urlPath;

	newString = enhanced_stringRemoveHttpHttpsInUrl(string);
	urlPath = enhanced_stringGetStringAfterFirstChar(newString, "/");

	return urlPath;
}

FString Uenhanced_stringBPLibrary::enhanced_stringClampString(FString string, int minLength, int maxLength)
{
	FString newString = "";
	int i = minLength;
	
	while(i < string.Len() && i <= maxLength)
	{
		newString += string[i];
		i++;
	}

	return newString;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsNumeric(TCHAR character)
{
	bool isNumeric;
	int numericLenth = 10;

	int i = 0;
	while (i < numericLenth && character != numericCharacters[i])
	{
		i++;
	}

	isNumeric = i < numericLenth;

	return isNumeric;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsAlpha(TCHAR character)
{
	bool isAlpha;
	int AlphaLenth = 26;

	int i = 0;
	while (i < AlphaLenth && ((character != lowerCharacters[i]) == (character != upperCharacters[i])))
	{
		i++;
	}

	isAlpha = i < AlphaLenth;

	return isAlpha;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsSpecial(TCHAR character)
{
	bool isSpecial;
	int specialLenth = enhanced_stringGetstringLength(specialCharacters);

	int i = 0;
	while (i < specialLenth && character != specialCharacters[i])
	{
		i++;
	}

	isSpecial = i < specialLenth;

	return isSpecial;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsUpper(TCHAR character)
{
	bool isUpper;
	int upperLenth = 26;

	int i = 0;
	while (i < upperLenth && character != upperCharacters[i])
	{
		i++;
	}

	isUpper = i < upperLenth;

	return isUpper;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsLower(TCHAR character)
{
	bool isLower;
	int lowerLenth = 26;

	int i = 0;
	while (i < lowerLenth && character != lowerCharacters[i])
	{
		i++;
	}

	isLower = i < lowerLenth;

	return isLower;
}

bool Uenhanced_stringBPLibrary::enhanced_stringContainsChar(FString string, TCHAR character)
{
	bool containsChar;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && string[i] != character)
	{
		i++;
	}

	containsChar = i < stringLength;

	return containsChar;
}

int64 Uenhanced_stringBPLibrary::enhanced_stringBinaryToDecimal(FString string)
{
	int64 decimal = 0;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		if (string[i] == '1')
		{
			decimal = decimal * 2 + 1;
		}
		else if (string[i] == '0')
		{
			decimal *= 2;
		}
	}

	return decimal;
}

FString Uenhanced_stringBPLibrary::test(FString string)
{
	return FString();
}

int Uenhanced_stringBPLibrary::enhanced_stringGetstringLength(FString string)
{
	return string.Len();
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsValidStringIndex(FString string, int index)
{
	bool isIndexValid;
	int stringLength = enhanced_stringGetstringLength(string);

	isIndexValid = (index >= 0 && index < stringLength);

	return isIndexValid;
}

bool Uenhanced_stringBPLibrary::enhanced_stringContainsSubStringInString(FString string, FString subString)
{
	int stringLength = enhanced_stringGetstringLength(string);
	int searchLenth = enhanced_stringGetstringLength(subString);
	bool isConainsInString;

	if (stringLength <= 0 || searchLenth < stringLength) { return false; }

	isConainsInString = string.Contains(subString);


	return isConainsInString;
}

int Uenhanced_stringBPLibrary::enhanced_stringCountSubStringInString(FString subString, FString string)
{
	int subStringCount = 0;
	int substringLength = enhanced_stringGetstringLength(subString);
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength - substringLength; i++)
	{
		int j = 0;

 		while (j < substringLength && string[i + j] == subString[j])
		{
			j++;

			if (j == substringLength) { subStringCount++; }
		}
	}

	return subStringCount;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGenerateRandomString(int minLenth, int maxLenth)
{
	FString randomString = "";
	FString characters = lowerCharacters + upperCharacters + numericCharacters + specialCharacters;
	int charactersLenth = enhanced_stringGetstringLength(characters);
	int lenth = FMath::RandRange(minLenth, maxLenth);

	randomString = enhanced_stringRandomString(characters, lenth);

	return randomString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGenerateCustomRandomString(FString randomCharacters, int minLenth, int maxLenth)
{
	FString randomString = "";
	int lenth = FMath::RandRange(minLenth, maxLenth);

	randomString = enhanced_stringRandomString(randomCharacters, lenth);

	return randomString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGenerateIPv4(EIPv4Class ipClass)
{
	FString IPv4;
	int randomNumber;
	int IPv4stringLength;

	switch (ipClass)
	{
	case(EIPv4Class::EIPv4C_A):
		randomNumber = FMath::RandRange(0, 127);
		break;

	case(EIPv4Class::EIPv4C_B):
		randomNumber = FMath::RandRange(128, 191);
		break;

	case(EIPv4Class::EIPv4C_C):
		randomNumber = FMath::RandRange(192, 223);
		break;

	case(EIPv4Class::EIPv4C_D):
		randomNumber = FMath::RandRange(224, 239);
		break;

	case(EIPv4Class::EIPv4C_E):
		randomNumber = FMath::RandRange(240, 255);
		break;

	case(EIPv4Class::EIPv4C_All): default:
		randomNumber = FMath::RandRange(0, 255);
		break;
	}

	IPv4.Append(FString::FromInt(randomNumber) + ".");

	for (int i = 1; i < 4; i++)
	{
		randomNumber = FMath::RandRange(0, 255);
		IPv4.Append(FString::FromInt(randomNumber) + ".");
	}

	IPv4stringLength = enhanced_stringGetstringLength(IPv4);

	IPv4.RemoveAt(IPv4stringLength - 1, 1);

	if (IPv4 == "172.0.0.1" || IPv4 == "0.0.0.0") { enhanced_stringGenerateIPv4(ipClass); }

	return IPv4;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGenerateIPv6()
{
	FString IPv6;
	FString currentSegement;
	FString digits = "0123456789ABCDEF";
	int randomDigit;
	int IPv6StringLength;

	for (int i = 0; i < 8; i++)
	{
		currentSegement = "";
		for (int j = 0; j < 4; j++)
		{
			randomDigit = FMath::RandRange(0, 15);
			currentSegement.AppendChar(digits[randomDigit]);
		}

		IPv6.Append(currentSegement);
		IPv6.AppendChar(':');
	}

	IPv6StringLength = enhanced_stringGetstringLength(IPv6);

	IPv6.RemoveAt(IPv6StringLength - 1, 1);

	if (IPv6 == "0000:0000:0000:0000:0000:0000:0000:0001" || IPv6 == "0000:0000:0000:0000:0000:0000:0000:0000") { enhanced_stringGenerateIPv6(); }

	return IPv6;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRandomizeString(FString string)
{
	FString newString;
	TArray<FString> stringCharacters = enhanced_stringGetCharArray(string);
	int stringLength = enhanced_stringGetstringLength(string);
	int randomIndex;


	for (int i = 0; i < stringLength; i++)
	{
		randomIndex = FMath::RandRange(0, stringLength - i - 1);

		newString.Append(stringCharacters[randomIndex]);
		stringCharacters.RemoveAt(randomIndex);
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringMoveLeft(FString string, int iteration)
{
	FString newString = string;
	int stringLength = enhanced_stringGetstringLength(string);
	int index;

	if (stringLength <= 0) { return string; }

	iteration %= stringLength;

	if (iteration == 0) { return string; }

	for (int i = 0; i < stringLength; i++)
	{
		index = (i + iteration) % stringLength;
		newString[i] = string[index];
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringMoveRight(FString string, int iteration)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);
	int index;

	iteration %= stringLength;

	if (iteration == 0) { return string; }

	for (int i = 0; i < stringLength; i++)
	{
		index = (i - iteration + stringLength) % stringLength;
		newString.AppendChar(string[index]);
	}
	return newString;
}


int32 Uenhanced_stringBPLibrary::enhanced_stringFindLastCharIndex(FString string, FString character)
{
	int index = -1;
	int stringLength = enhanced_stringGetstringLength(string);

	if (!enhanced_stringIsValidStringIndex(character, 0)) { return index; }

	for (int i = 0; i < stringLength; i++)
	{
		if (string[i] == character[0])
		{
			index = i;
		}
	}

	return index;
}

int32 Uenhanced_stringBPLibrary::enhanced_stringFindFirstCharIndex(FString string, FString character)
{
	int index = -1;
	int stringLength = enhanced_stringGetstringLength(string);

	if (!enhanced_stringIsValidStringIndex(character, 0)) { return index; }

	int i = 0;
	while (i < stringLength && string[i] != character[0])
	{
		i++;
	}

	return i < stringLength;
}

TArray<FString> Uenhanced_stringBPLibrary::enhanced_stringGetCharArray(FString string)
{
	TArray<FString> stringArray;

	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		FString newString;
		newString.AppendChar(string[i]);
		stringArray.Add(newString);
	}

	return stringArray;
}

/*
TArray<TCHAR> Uenhanced_stringBPLibrary::enhanced_stringGetCharArray(FString string)
{
	TArray<TCHAR> charArray;
	int stringLength = enhanced_stringGetstringLength(string);

	for(int i = 0; i < stringLength; i++)
	{
		charArray.Add(string[i]);
	}

	return charArray;
}

FString Uenhanced_stringBPLibrary::enhanced_stringInsertAt(FString string, TCHAR character, int index)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < index; i++)
	{
		newString.AppendChar(string[i]);
	}

	newString.AppendChar(character);

	for(int i = index + 1; i < stringLength; i++)
	{
		newString.AppendChar(string[i]);
	}

	return newString;
}*/

FString Uenhanced_stringBPLibrary::enhanced_stringInsertStringAt(FString string, FString insertString, int index)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	if (!enhanced_stringIsValidStringIndex(string, index)) { return string; }

	for (int i = 0; i < index; i++)
	{
		newString.AppendChar(string[i]);
	}

	newString.Append(insertString);

	for (int i = index + 1; i < stringLength; i++)
	{
		newString.AppendChar(string[i]);
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveAt(FString string, int index)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	if (!enhanced_stringIsValidStringIndex(string, index)) { return string; }

	for (int i = 0; i < index; i++)
	{
		newString.AppendChar(string[i]);
	}

	for (int i = index + 1; i < stringLength; i++)
	{
		newString.AppendChar(string[i]);
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveSpaces(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		if (string[i] != ' ')
		{
			newString.AppendChar(string[i]);
		}
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveNumerics(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		if (!enhanced_stringIsNumeric(string[i]))
		{
			newString.AppendChar(string[i]);
		}
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveAlphas(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		if (!enhanced_stringIsAlpha(string[i]))
		{
			newString.AppendChar(string[i]);
		}
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetStringAfterChar(FString string, FString character, int count)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);
	int lastCharacterIndex = 0;
	int currentCount = 0;

	if (character.IsEmpty()) { character = ""; }

	for (int i = 0; i < stringLength && currentCount < count; i++)
	{
		if (string[i] == character[0])
		{
			lastCharacterIndex = i;
			currentCount++;
		}
	}

	lastCharacterIndex++;

	if (lastCharacterIndex <= 1 || lastCharacterIndex > stringLength) { return string; }

	for (int i = lastCharacterIndex; i < stringLength; i++)
	{
		newString.AppendChar(string[i]);
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveSpecials(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		if (!enhanced_stringIsSpecial(string[i]))
		{
			newString.AppendChar(string[i]);
		}
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveUpper(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		if (!enhanced_stringIsUpper(string[i]))
		{
			newString.AppendChar(string[i]);
		}
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetStringBeforeChar(FString string, FString character, int count)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);
	int lastCharacterIndex = 0;
	int currentCount = 0;

	if (character.IsEmpty()) { character = ""; }

	for (int i = 0; i < stringLength && currentCount < count; i++)
	{
		if (string[i] == character[0])
		{
			lastCharacterIndex = i;
			currentCount++;
		}
	}

	if (lastCharacterIndex <= 1 || lastCharacterIndex > stringLength) { return string; }

	for (int i = 0; i < lastCharacterIndex; i++)
	{
		newString.AppendChar(string[i]);
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetStringAfterFirstChar(FString string, FString character)
{
	FString newString;

	newString = enhanced_stringGetStringAfterChar(string, character, 1);

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetStringBeforeFirstChar(FString string, FString character)
{
	FString newString;

	newString = enhanced_stringGetStringBeforeChar(string, character, 1);

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetStringAfterLastChar(FString string, FString character)
{
	FString newString;
	int stringLength;

	stringLength = enhanced_stringGetstringLength(string);

	newString = enhanced_stringGetStringAfterChar(string, character, stringLength);

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetStringBeforeLastChar(FString string, FString character)
{
	FString newString;
	int stringLength;

	stringLength = enhanced_stringGetstringLength(string);

	newString = enhanced_stringGetStringBeforeChar(string, character, stringLength);

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetUrlSubDomain(FString string)
{
	TArray<FString> splitedString;
	bool isUrlValid;

	isUrlValid = enhanced_stringIsUrlFormat(string) == 0;

	if (!isUrlValid) { return ""; }

	splitedString = enhanced_stringGetSplitedUrl(string);

	return splitedString[0];
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetUrlTLD(FString string)
{
	FString newString;
	TArray<FString> splitedString;
	bool isUrlValid;

	isUrlValid = enhanced_stringIsUrlFormat(string) == 0;

	if (!isUrlValid) { return ""; }

	splitedString = enhanced_stringGetSplitedUrl(string);

	splitedString.RemoveAt(0); // remove subDomain
	splitedString.RemoveAt(0); // remove domain

	for (int i = 0; i < splitedString.Num(); i++)
	{
		newString.Append(splitedString[i]);
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetUrlDomain(FString string)
{
	TArray<FString> splitedString;
	bool isUrlValid;

	isUrlValid = enhanced_stringIsUrlFormat(string) == 0;

	if (!isUrlValid) { return ""; }

	splitedString = enhanced_stringGetSplitedUrl(string);

	return splitedString[1];
}


FString Uenhanced_stringBPLibrary::enhanced_stringRemoveLower(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		if (!enhanced_stringIsLower(string[i]))
		{
			newString.AppendChar(string[i]);
		}
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveMultipleSpaces(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		newString.AppendChar(string[i]);

		if (string[i] == ' ')
		{
			while (i < stringLength && string[i + 1] == ' ')
			{
				i++;
			}
		}
	}

	return newString;
}

TArray<FString> Uenhanced_stringBPLibrary::enhanced_stringSplitBySeparator(FString string, FString separator)
{
	TArray<FString> stringArray;
	int stringLength = enhanced_stringGetstringLength(string);

	if (!enhanced_stringIsValidStringIndex(separator, 0)) { return stringArray; }

	for (int i = 0; i < stringLength; i++)
	{
		stringArray.Add("");

		while (i < stringLength && string[i] != separator[0])
		{
			stringArray[stringArray.Num() - 1].AppendChar(string[i]);
			i++;
		}
	}

	if (stringArray.Num() == 0) { return stringArray; }

	if (stringArray[stringArray.Num() - 1] == "") { stringArray.RemoveAt(stringArray.Num() - 1); }

	return stringArray;

}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveChars(FString string, FString characters)
{
	FString newString;
	FString stringToTest;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		stringToTest.AppendChar(string[i]);
		if (!enhanced_stringContainsChars(stringToTest, characters))
		{
			newString.AppendChar(string[i]);
		}
		stringToTest = NULL;
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringToLower(FString string)
{
	FString newString = string.ToLower();

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringToUpper(FString string)
{
	FString newString = string.ToUpper();

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringInvertString(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	for (int i = stringLength - 1; i >= 0; i--)
	{
		newString.AppendChar(string[i]);
	}

	return newString;

}

FString Uenhanced_stringBPLibrary::enhanced_stringToCamelCase(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	if (stringLength < 2) { return newString; }

	newString.AppendChar(enhanced_stringGetLowerCharacter(string[0]));

	for (int i = 1; i < stringLength; i++)
	{
		if (string[i] == ' ')
		{
			bool isNextIndexValid = enhanced_stringIsValidStringIndex(string, i + 1);

			if (isNextIndexValid)
			{
				newString.AppendChar(enhanced_stringGetUpperCharacter(string[i + 1]));
				i++;
			}
		}
		else
		{
			newString.AppendChar(string[i]);
		}
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringToPascalCase(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	if (stringLength < 2) { return newString; }

	newString.AppendChar(enhanced_stringGetUpperCharacter(string[0]));

	for (int i = 1; i < stringLength; i++)
	{
		if (string[i] == ' ')
		{
			bool isNextIndexValid = enhanced_stringIsValidStringIndex(string, i + 1);

			if (isNextIndexValid)
			{
				newString.AppendChar(enhanced_stringGetUpperCharacter(string[i + 1]));
				i++;
			}
		}
		else
		{
			newString.AppendChar(string[i]);
		}
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringToSnakeCase(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	if (stringLength < 2) { return newString; }


	for (int i = 0; i < stringLength; i++)
	{
		if (string[i] == ' ')
		{
			newString.AppendChar('_');
		}
		else
		{
			newString.AppendChar(enhanced_stringGetLowerCharacter(string[i]));
		}
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringToKebabCase(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	if (stringLength < 2) { return newString; }


	for (int i = 0; i < stringLength; i++)
	{
		if (string[i] == ' ')
		{
			newString.AppendChar('-');
		}
		else
		{
			newString.AppendChar(enhanced_stringGetLowerCharacter(string[i]));
		}
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringToTitleCase(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	if (stringLength < 2) { return newString; }

	newString.AppendChar(enhanced_stringGetUpperCharacter(string[0]));

	for (int i = 1; i < stringLength; i++)
	{
		newString.AppendChar(enhanced_stringGetLowerCharacter(string[i]));
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringInvertCase(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);
	bool isUpper;

	if (stringLength < 1) { return string; }


	for (int i = 0; i < stringLength; i++)
	{
		isUpper = enhanced_stringGetUpperCharacter(string[i]) == string[i];
		newString.AppendChar(isUpper ? enhanced_stringGetLowerCharacter(string[i]) : enhanced_stringGetUpperCharacter(string[i]));
		isUpper = !isUpper;
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringAlternateCase(FString string)
{
	FString newString;
	int stringLength = enhanced_stringGetstringLength(string);

	if (stringLength < 1) { return string; }

	bool isUpper = enhanced_stringGetUpperCharacter(string[0]) == string[0];

	for (int i = 0; i < stringLength; i++)
	{
		newString.AppendChar(isUpper ? enhanced_stringGetUpperCharacter(string[0]) : enhanced_stringGetLowerCharacter(string[0]));
		isUpper = !isUpper;
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringTrimStart(FString string)
{
	FString newString;
	int startIndex;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && string[i] == ' ')
	{
		i++;
	}

	startIndex = i;

	newString = string.Mid(startIndex);

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringTrimEnd(FString string)
{
	FString newString;
	int endIndex;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = stringLength - 1;
	while (i >= 0 && string[i] == ' ')
	{
		i--;
	}

	endIndex = i;

	newString = string.Left(endIndex + 1);

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringTrimStartEnd(FString string)
{
	FString newString;

	newString = enhanced_stringTrimStart(string);
	newString = enhanced_stringTrimEnd(newString);

	return newString;
}


FString Uenhanced_stringBPLibrary::enhanced_stringTrimQuotes(FString string)
{
	FString newString = string;
	int stringLength = enhanced_stringGetstringLength(string);

	if (newString.StartsWith(TEXT("\"")))
	{
		newString.RemoveAt(0);
	}

	if (newString.EndsWith(TEXT("\"")))
	{
		newString.RemoveAt(stringLength - 1);
	}

	return newString;
}


bool Uenhanced_stringBPLibrary::enhanced_stringConvertStringIntoBool(FString string)
{
	return string.ToBool();
}

FDateTime Uenhanced_stringBPLibrary::enhanced_stringConvertStringToDatetime(FString string, FString separator)
{
	/*
		string will be convert like this -->	Year	Month	Day			Hour	Minute	  Second	Millisecond
										String " 0		  0      0           0        0         0            0
		if string contains less than all dateTime values, remaining values with no "data" will become 0.
	*/
	FString newString;
	TArray<FString> splitedString;
	int32 values[7] = { 0 };
	int maxNum = 0;

	if (separator.IsEmpty()) { separator = " "; }

	newString = enhanced_stringRemoveAlphas(string);
	newString = enhanced_stringRemoveChars(newString, specialCharacters);
	newString = enhanced_stringRemoveMultipleSpaces(newString);

	splitedString = enhanced_stringSplitBySeparator(newString, separator);

	maxNum = splitedString.Num() > 7 ? 7 : splitedString.Num();

	if (maxNum <= 0) { return FDateTime(); }

	for (int i = 0; i < maxNum; i++)
	{
		values[i] = FCString::Atoi(*splitedString[i]);
	}

	// check values
	values[0] = values[0] < 1 || values[0] > MAX_int32 ? 1 : values[0]; // Year
	values[1] = values[1] < 1 || values[1] > 12 ? 1 : values[1];		// Month
	values[2] = values[2] < 1 || values[2] > 31 ? 1 : values[2];		// Day
	values[3] = values[3] < 0 || values[3] > 24 ? 0 : values[3];		// Hour
	values[4] = values[4] < 0 || values[4] > 60 ? 0 : values[4];		// Minute
	values[5] = values[5] < 0 || values[5] > 60 ? 0 : values[5];		// Second
	values[6] = values[6] < 0 || values[6] > 60 ? 0 : values[6];		// Millisecond


	FDateTime dateTime(values[0], values[1], values[2], values[3], values[4], values[5], values[6]);

	return dateTime;
}

FRotator Uenhanced_stringBPLibrary::enhanced_stringConvertStringToRotator(FString string, FString separator)
{
	FRotator rotator = { 0.f, 0.f, 0.f };
	FString newString;
	FString newSpecialCharacters;
	double values[3];
	int maxNum;
	TArray<FString> splitedString;

	if (separator.IsEmpty()) { separator = " "; }

	// remove the '-' to not change the negative values into positives
	newSpecialCharacters = enhanced_stringRemoveChars(specialCharacters, "-");

	newString = enhanced_stringRemoveAlphas(string);
	newString = enhanced_stringRemoveChars(newString, newSpecialCharacters);
	newString = enhanced_stringRemoveMultipleSpaces(newString);

	splitedString = enhanced_stringSplitBySeparator(newString, separator);

	maxNum = splitedString.Num() > 3 ? 3 : splitedString.Num();

	for (int i = 0; i < maxNum; i++)
	{
		values[i] = FCString::Atod(*splitedString[i]);
	}

	rotator.Pitch = values[0];
	rotator.Yaw = values[1];
	rotator.Roll = values[2];

	return rotator;
}

FVector Uenhanced_stringBPLibrary::enhanced_stringConvertStringTo3dVector(FString string, FString separator)
{
	FVector vector = { 0.f, 0.f, 0.f };
	FString newString;
	FString newSpecialCharacters;
	double value;
	int maxNum;
	TArray<FString> splitedString;

	if (separator.IsEmpty()) { separator = " "; }

	// remove the '-' to not change the negative values to positive
	newSpecialCharacters = enhanced_stringRemoveChars(specialCharacters, "-");

	newString = enhanced_stringRemoveAlphas(string);
	newString = enhanced_stringRemoveChars(newString, newSpecialCharacters);
	newString = enhanced_stringRemoveMultipleSpaces(newString);

	splitedString = enhanced_stringSplitBySeparator(newString, separator);

	maxNum = splitedString.Num() > 3 ? 3 : splitedString.Num();

	for (int i = 0; i < maxNum; i++)
	{
		value = FCString::Atod(*splitedString[i]);
		vector[i] = value;
	}

	return vector;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveFromStart(FString string, FString inPrefix)
{
	bool isPrefixInString;
	int stringLength = enhanced_stringGetstringLength(string);
	int inPrefixLength = enhanced_stringGetstringLength(inPrefix);

	if (inPrefixLength >= stringLength)
	{
		if (string == inPrefix)
		{
			return "";
		}

		return string;
	}

	int i = 0;
	while (i < inPrefixLength && string[i] == inPrefix[i])
	{
		i++;
	}

	isPrefixInString = i == inPrefixLength;

	if (isPrefixInString)
	{
		return string.Mid(inPrefixLength);
	}

	return string;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveFromEnd(FString string, FString inPrefix)
{
	bool isPrefixInString;
	int stringLength = enhanced_stringGetstringLength(string);
	int inPrefixLength = enhanced_stringGetstringLength(inPrefix);

	if (inPrefixLength >= stringLength)
	{
		if (string == inPrefix)
		{
			return "";
		}

		return string;
	}

	int i = stringLength - 1;
	int j = inPrefixLength - 1;
	while (j >= 0 && string[i] == inPrefix[j])
	{
		i--;
		j--;
	}

	isPrefixInString = j < 0;

	if (isPrefixInString)
	{
		return string.LeftChop(inPrefixLength);
	}

	return string;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveFromStartAndEnd(FString string, FString inPrefix)
{
	FString newString;

	newString = enhanced_stringRemoveFromStart(string, inPrefix);
	newString = enhanced_stringRemoveFromEnd(newString, inPrefix);

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveString(FString string, FString subString)
{
	FString newString;
	int stringLength;
	int subStringLength;
	int i = 0;

	stringLength = enhanced_stringGetstringLength(string);
	subStringLength = enhanced_stringGetstringLength(subString);

	for (i = 0; i <= stringLength - subStringLength;)
	{
		if (string.Mid(i, subStringLength) == subString)
		{
			i += subStringLength;
		}
		else
		{
			newString.AppendChar(string[i]);
			i++;
		}
	}

	if (i < stringLength)
	{
		newString.Append(*string.Mid(i));
	}

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringRemoveStrings(FString string, TArray<FString> subStrings)
{
	FString newString = string;

	for (int i = 0; i < subStrings.Num(); i++)
	{
		if (subStrings[i].IsEmpty()) { continue; }
		newString = enhanced_stringRemoveString(newString, subStrings[i]);
	}

	return newString;
}

TArray<FString> Uenhanced_stringBPLibrary::enhanced_stringRemoveDuplicatesFromStringArray(TArray<FString> stringArray)
{
	TArray<FString> newStringArray;

	for (int i = 0; i < stringArray.Num(); i++)
	{
		if (!enhanced_stringIsStringInStringArray(stringArray[i], newStringArray))
		{
			newStringArray.Add(stringArray[i]);
		}
	}

	return newStringArray;
}


FColor Uenhanced_stringBPLibrary::enhanced_stringConvertStringToColor(FString string, FString separator)
{
	FColor color = { 0, 0, 0, 0 };
	FString newString;
	int16 values[4] = { 0 };
	TArray<FString> splitedString;

	if (separator.IsEmpty()) { separator = " "; }

	newString = enhanced_stringRemoveAlphas(string);
	newString = enhanced_stringRemoveChars(newString, specialCharacters);
	newString = enhanced_stringRemoveMultipleSpaces(newString);

	splitedString = enhanced_stringSplitBySeparator(newString, separator);

	for (int i = 0; i < 4 && i < splitedString.Num(); i++)
	{
		values[i] = FCString::Atoi(*splitedString[i]);
	}

	color.R = values[0];
	color.G = values[1];
	color.B = values[2];
	color.A = values[3];

	return color;
}

FString Uenhanced_stringBPLibrary::enhanced_stringConvertColorToString(FColor color)
{
	FString colorString = "(";

	colorString += "R=" + FString::FromInt(color.R) + ",";
	colorString += "G=" + FString::FromInt(color.G) + ",";
	colorString += "B=" + FString::FromInt(color.B) + ",";
	colorString += "A=" + FString::FromInt(color.A) + ")";

	return colorString;
}

FLinearColor Uenhanced_stringBPLibrary::enhanced_stringConvertStringToLinearColor(FString string, FString separator)
{
	FLinearColor color = { 0.f, 0.f, 0.f, 0.f };
	FString newString;
	float values[4] = { 0 };
	TArray<FString> splitedString;

	if (separator.IsEmpty()) { separator = " "; }

	newString = enhanced_stringRemoveAlphas(string);
	newString = enhanced_stringRemoveChars(newString, specialCharacters);
	newString = enhanced_stringRemoveMultipleSpaces(newString);

	splitedString = enhanced_stringSplitBySeparator(newString, separator);

	for (int i = 0; i < 4 && i < splitedString.Num(); i++)
	{
		values[i] = FCString::Atof(*splitedString[i]);
	}

	color.R = values[0];
	color.G = values[1];
	color.B = values[2];
	color.A = values[3];

	return color;
}

FVector2D Uenhanced_stringBPLibrary::enhanced_stringConvertStringTo2dVector(FString string, FString separator)
{
	FVector2D vector;
	FString newString;
	FString newSpecialCharacters;
	double value;
	TArray<FString> splitedString;

	if (separator.IsEmpty()) { separator.AppendChar(' '); }

	// remove the '-' to not change the negative values to positive
	newSpecialCharacters = enhanced_stringRemoveChars(specialCharacters, "-");

	newString = enhanced_stringRemoveAlphas(string);
	newString = enhanced_stringRemoveChars(newString, newSpecialCharacters);
	newString = enhanced_stringRemoveMultipleSpaces(newString);

	splitedString = enhanced_stringSplitBySeparator(newString, separator);

	for (int i = 0; i < 2 && i < splitedString.Num(); i++)
	{
		value = FCString::Atod(*splitedString[i]);
		vector[i] = value;
	}

	return vector;
}

bool Uenhanced_stringBPLibrary::enhanced_stringAreSpecials(FString string)
{
	bool areSpecials;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && enhanced_stringIsSpecial(string[i]))
	{
		i++;
	}

	areSpecials = i == stringLength;

	return areSpecials;
}

bool Uenhanced_stringBPLibrary::enhanced_stringAreAlphas(FString string)
{
	bool areAlphas;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && enhanced_stringIsAlpha(string[i]))
	{
		i++;
	}

	areAlphas = i == stringLength;

	return areAlphas;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsStringInStringArray(FString string, TArray<FString> stringsArray)
{
	bool isInStringArray;

	int i = 0;
	while (i < stringsArray.Num() && string != stringsArray[i])
	{
		i++;
	}

	isInStringArray = i < stringsArray.Num();

	return isInStringArray;
}

bool Uenhanced_stringBPLibrary::enhanced_stringAreNumerics(FString string)
{
	bool areNumerics;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && enhanced_stringIsNumeric(string[i]))
	{
		i++;
	}

	areNumerics = i == stringLength;

	return areNumerics;
}

bool Uenhanced_stringBPLibrary::enhanced_stringAreUppers(FString string)
{
	bool areUppers;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && enhanced_stringIsUpper(string[i]))
	{
		i++;
	}

	areUppers = i == stringLength;

	return areUppers;
}

bool Uenhanced_stringBPLibrary::enhanced_stringAreLowers(FString string)
{
	bool areLower;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && enhanced_stringIsLower(string[i]))
	{
		i++;
	}

	areLower = i == stringLength;

	return areLower;
}

/*

TSet<int32> Uenhanced_stringBPLibrary::enhanced_stringConvertStringToIntTSet(FString string, FString separator)
{
	TSet<int32> TSet;
	TArray<FString> stringArray;

	if (separator.IsEmpty()) { separator.AppendChar(' '); }

	string.ParseIntoArray(stringArray, &separator[0], true);

	for (int i = 0; i < stringArray.Num(); i++)
	{
		int32 value = FCString::Atoi(*stringArray[i]);
		TSet.Add(value);
	}

	return TSet;
}


TSet<float> Uenhanced_stringBPLibrary::enhanced_stringConvertStringToFloatTSet(FString string, FString separator)
{
	TSet<float> TSet;
	TArray<FString> stringArray;

	if (separator.IsEmpty()) { separator.AppendChar(' '); }

	string.ParseIntoArray(stringArray, &separator[0], true);

	for (int i = 0; i < stringArray.Num(); i++)
	{
		float value = FCString::Atof(*stringArray[i]);
		TSet.Add(value);
	}

	return TSet;
}
*/

int64 Uenhanced_stringBPLibrary::enhanced_stringConvertBinaryStringToInt(FString string)
{
	return enhanced_stringConvertCustomBaseStringToInt(string, 2);
}

bool Uenhanced_stringBPLibrary::enhanced_stringContainsNumeric(FString string)
{
	bool containsNumeric;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && !enhanced_stringIsNumeric(string[i]))
	{
		i++;
	}

	containsNumeric = i < stringLength;

	return containsNumeric;
}

bool Uenhanced_stringBPLibrary::enhanced_stringContainsAlpha(FString string)
{
	bool containsAlpha;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && !enhanced_stringIsAlpha(string[i]))
	{
		i++;
	}

	containsAlpha = i < stringLength;

	return containsAlpha;
}

bool Uenhanced_stringBPLibrary::enhanced_stringContainsSpecial(FString string)
{
	bool containsSpecial;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && !enhanced_stringIsSpecial(string[i]))
	{
		i++;
	}

	containsSpecial = i < stringLength;

	return containsSpecial;
}

bool Uenhanced_stringBPLibrary::enhanced_stringContainsUpper(FString string)
{
	bool containsUpper;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && !enhanced_stringIsUpper(string[i]))
	{
		i++;
	}

	containsUpper = i < stringLength;

	return containsUpper;
}

bool Uenhanced_stringBPLibrary::enhanced_stringContainsChars(FString string, FString characters)
{
	bool contains = false;
	int stringLength = enhanced_stringGetstringLength(string);
	int charactersLength = enhanced_stringGetstringLength(characters);

	if (stringLength < 1 || charactersLength < 1) { return false; }

	for (int i = 0; i < stringLength; i++)
	{
		int j = 0;
		while (j < charactersLength && string[i] != characters[j])
		{
			j++;
		}

		contains = j < charactersLength;

		if (contains) { break; }
	}

	return contains;
}

bool Uenhanced_stringBPLibrary::enhanced_stringStringArrayContainsSubString(TArray<FString> stringArray,
	FString subString)
{
	int i = 0;
	while(i < stringArray.Num() && enhanced_stringContainsSubStringInString(stringArray[i], subString))
	{
		i++;
	}

	return i < stringArray.Num();
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsEmailDomainFormat(FString string, TArray<FString> domains)
{
	TArray<FString> splitedString;
	bool isEmailFormat;

	isEmailFormat = enhanced_stringIsEmailFormat(string) == 0;
	if (!isEmailFormat) { return false; }

	splitedString = enhanced_stringSplitBySeparator(string, "@");

	int i = 0;
	while (i < domains.Num() && splitedString[1] != domains[i])
	{
		i++;
	}

	return i < domains.Num();
}

FString Uenhanced_stringBPLibrary::enhanced_stringConvertIntToBinaryString(int32 value)
{
	return enhanced_stringConvertIntToCustomBaseString(value, 2);
}

FString Uenhanced_stringBPLibrary::enhanced_stringConvertDateTimeToString(FDateTime datetime)
{
	FString newString;

	newString = "Year=" + FString::FromInt(datetime.GetYear());
	newString += " Month=" + FString::FromInt(datetime.GetMonth());
	newString += " Day=" + FString::FromInt(datetime.GetDay());
	newString += " Hour=" + FString::FromInt(datetime.GetHour());
	newString += " Minute=" + FString::FromInt(datetime.GetMinute());
	newString += " Second=" + FString::FromInt(datetime.GetSecond());
	newString += " Millisecond=" + FString::FromInt(datetime.GetMillisecond());

	return newString;
}

int64 Uenhanced_stringBPLibrary::enhanced_stringConvertCustomBaseStringToInt(FString string, int32 base)
{
	int stringLength;
	int64 value = 0;
	int64 digitValue;
	TCHAR currentChar;

	stringLength = enhanced_stringGetstringLength(string);

	for (int i = 0; i < stringLength; i++)
	{
		value *= base;
		currentChar = string[i];
		digitValue = 0;

		if (currentChar >= '0' && currentChar <= '9')
		{
			digitValue = currentChar - '0';
		}
		else if (currentChar >= 'a' && currentChar <= 'f')
		{
			digitValue = currentChar - 'a' + 10;
		}
		else if (currentChar >= 'A' && currentChar <= 'F')
		{
			digitValue = currentChar - 'A' + 10;
		}
		else
		{
			return 0;
		}

		if (digitValue >= base) { return 0; }

		value += digitValue;
	}

	return value;
}

int64 Uenhanced_stringBPLibrary::enhanced_stringConvertHexadecimalStringToInt(FString string)
{
	int64 value = 0;
	FString cleanedHexaString = string.StartsWith("0x") ? string.Mid(2) : string;

	value = enhanced_stringConvertCustomBaseStringToInt(cleanedHexaString, 16);

	return value;
}

int64 Uenhanced_stringBPLibrary::enhanced_stringConvertOctalStringToInt(FString string)
{
	int64 value = 0;
	FString cleanedOctalString = string.StartsWith("0") ? string.Mid(1) : string;

	value = enhanced_stringConvertCustomBaseStringToInt(cleanedOctalString, 8);

	return value;
}

FString Uenhanced_stringBPLibrary::enhanced_stringConvertIntToHexadecimalString(int32 value)
{
	return enhanced_stringConvertIntToCustomBaseString(value, 16);
}

FString Uenhanced_stringBPLibrary::enhanced_stringConvertIntToCustomBaseString(int32 value, int32 base)
{
	FString baseNString;
	FString digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digit;
	int newValue = value;

	if (base < 2 || base > 36) { return "INVALID_BASE"; }

	do
	{
		digit = newValue % base;
		baseNString = FString(1, &digits[digit]) + baseNString;
		newValue /= base;
	} while (newValue > 0);

	return baseNString;
}


int32 Uenhanced_stringBPLibrary::enhanced_stringIsEmailFormat(FString string)
{
	FString allowedCharacters = lowerCharacters + numericCharacters + "-_/@.";
	TArray<FString> splitedString;

	bool containsSpace;
	bool atRightPlace;
	bool dotRightPlace;

	int stringLength;
	int splitedstringLength;
	int atNumber;
	int dotNumber;

	stringLength = enhanced_stringGetstringLength(string);

	containsSpace = enhanced_stringContainsChar(string, ' ');
	if (containsSpace) { return 1; }


	int i = 0;
	while (i < stringLength && enhanced_stringContainsChar(allowedCharacters, string[i]))
	{
		i++;
	}

	if (i < stringLength) { return 2; }

	dotNumber = enhanced_stringCountSubStringInString(".", string);
	if (dotNumber != 1) { return 3; }

	splitedString = enhanced_stringSplitBySeparator(string, ".");
	splitedstringLength = enhanced_stringGetstringLength(splitedString[0]);

	atNumber = enhanced_stringCountSubStringInString("@", splitedString[0]);
	if (atNumber != 1) { return 4; }

	atRightPlace = splitedString[0][0] != '@' && splitedString[0][splitedstringLength - 1] != '@';
	if (!atRightPlace) { return 5; }

	dotRightPlace = string[splitedstringLength] == '.';
	if (!dotRightPlace) { return 6; }

	return 0;
}

int32 Uenhanced_stringBPLibrary::enhanced_stringIsUrlFormat(FString string)
{
	TArray<FString> splitedString;
	bool isHttp;
	bool isHttps;

	isHttp = string.StartsWith(startUrl[0]);
	isHttps = string.StartsWith(startUrl[1]);

	if (isHttp == isHttps) { return 1; }

	splitedString = enhanced_stringGetSplitedUrl(string);

	if (splitedString.Num() < 3) { return 2; }

	return 0;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsUrlTLDFormat(FString string, TArray<FString> TLD)
{
	bool isUrlFormat;
	bool isTLDInString;
	FString stringDomain = "";
	TArray<FString> splitedString;
	int stringDomainLenth;

	isUrlFormat = enhanced_stringIsUrlFormat(string) == 0;
	if (!isUrlFormat) { return false; }

	splitedString = enhanced_stringGetSplitedUrl(string);

	for (int i = 2; i < splitedString.Num(); i++)
	{
		stringDomain += splitedString[i] + ".";
	}

	stringDomainLenth = enhanced_stringGetstringLength(stringDomain);
	stringDomain.RemoveAt(stringDomainLenth - 1);

	isTLDInString = enhanced_stringIsStringInStringArray(stringDomain, TLD);

	return isTLDInString;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsUrlDomainFormat(FString string, TArray<FString> domains)
{
	TArray<FString> splitedString;
	bool isUrlFormat;
	bool isDomainInString;

	isUrlFormat = enhanced_stringIsUrlFormat(string) == 0;
	if (!isUrlFormat) { return false; }

	splitedString = enhanced_stringGetSplitedUrl(string);

	isDomainInString = enhanced_stringIsStringInStringArray(splitedString[1], domains);

	return isDomainInString;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsUrlDomainAndSubdomainFormat(FString string, TArray<FString> domains, TArray<FString> subDomains)
{
	bool isDomainCorrect;
	bool isSubdomainCorrect;

	isDomainCorrect = enhanced_stringIsUrlDomainFormat(string, domains);
	isSubdomainCorrect = enhanced_stringIsUrlSubdomainFormat(string, subDomains);

	return isDomainCorrect && isSubdomainCorrect;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetUrlPathAsString(FString string)
{
	return enhanced_stringGetUrlPath(string);
}

FString Uenhanced_stringBPLibrary::enhanced_stringConvertIntToOctalString(int32 value)
{
	return enhanced_stringConvertIntToCustomBaseString(value, 8);
}

TArray<FString> Uenhanced_stringBPLibrary::enhanced_stringGetUrlPathAsStringArray(FString string)
{
	FString urlPath;
	TArray<FString> urlPathArray;

	urlPath = enhanced_stringGetUrlPath(string);
	urlPathArray = enhanced_stringSplitBySeparator(urlPath, "/");

	return urlPathArray;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsIPv4Format(FString string)
{
	TArray<FString> splitedString;
	bool isIPv4Format;
	int32 value;

	splitedString = enhanced_stringSplitBySeparator(string, ".");

	if (splitedString.Num() != 4) { return false; }

	int i = 0;
	for (i; i < 4 && enhanced_stringAreNumerics(splitedString[i]); i++)
	{
		value = FCString::Atoi(*splitedString[i]);
		if (value < 0 || value > 255)
		{
			continue;
		}
	}

	isIPv4Format = i == 4;

	return isIPv4Format;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsIPv6Format(FString string)
{
	TArray<FString> splitedString;
	TArray<FString> groups;
	TArray<FString> subGroups;
	const FRegexPattern Pattern(TEXT("^[0-9a-fA-F]{1,4}$"));

	if (string == "::") return true;

	string.ParseIntoArray(splitedString, TEXT("::"), true);

	if (splitedString.Num() > 2) { return false; }

	for (int i = 0; i < splitedString.Num(); i++)
	{
		subGroups = enhanced_stringSplitBySeparator(splitedString[i], ":");
		groups.Append(subGroups);
	}


	if (splitedString.Num() > 0 && splitedString.Num() <= 2)
	{
		while (groups.Num() < 8)
		{
			groups.Add(TEXT("0"));
		}
	}

	if (groups.Num() != 8) { return false; }

	for (int i = 0; i < groups.Num(); i++)
	{
		FRegexMatcher Matcher(Pattern, groups[i]);

		if (!Matcher.FindNext()) { return false; }
	}

	return true;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsHexadecimalFormat(FString string)
{
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && FChar::IsHexDigit(string[i]))
	{
		i++;
	}

	return i == stringLength;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsBinaryFormat(FString string)
{
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && (string[i] == '0' || string[i] == '1'))
	{
		i++;
	}

	return i == stringLength;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsOctalFormat(FString string)
{
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && FChar::IsOctDigit(string[i]))
	{
		i++;
	}

	return i == stringLength;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsFileFormat(FString string, TArray<FString> extensions)
{
	FString stringExtension;
	TArray<FString> splitedString;

	splitedString = enhanced_stringSplitBySeparator(string, ".");

	if (splitedString.Num() < 2) { return false; }

	stringExtension = splitedString[splitedString.Num() - 1];

	int i = 0;
	while (i < extensions.Num() && stringExtension != extensions[i])
	{
		i++;
	}

	return i < extensions.Num();
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsImageFormat(FString string)
{
	TArray<FString> imageExtensions = { "jpg", "jpeg", "png", "gif", "bmp", "tif", "tiff", "ico", "svg", "webp", "heif", "heic", "raw", "indd", "ai", "eps", "pdf", "psd", "tga", "dds", "exr", "apng", "flif", "jxr", "dng", "jp2", "mng", "pcx", "pgf", "sgi", "ras", "tiff", "wbmp", "xpm" };
	bool isImageFormat;

	isImageFormat = enhanced_stringIsFileFormat(string, imageExtensions);

	return isImageFormat;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsVideoFormat(FString string)
{
	TArray<FString> videoExtensions = { "mp4", "mkv", "flv", "avi", "mov", "wmv", "rm", "rmvb", "webm", "vob", "ogv", "m4v", "3gp", "3g2", "f4v", "f4p", "f4a", "f4b", "drc", "gifv", "mng", "qt", "yuv", "asf", "amv", "mpg", "mp2", "mpeg", "mpe", "mpv", "svi", "roq", "nsv" };
	bool isVideoFormat;

	isVideoFormat = enhanced_stringIsFileFormat(string, videoExtensions);

	return isVideoFormat;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsAudioFormat(FString string)
{
	TArray<FString> AudioExtensions = { "mp3", "wav", "ogg", "flac", "aac", "m4a", "aiff", "wma", "alac", "amr", "dct", "au", "raw", "dff", "dsf", "mka", "m4b", "m4p", "mpc", "opus", "ra", "rm", "tta", "voc", "wv" };
	bool isAudioFormat;

	isAudioFormat = enhanced_stringIsFileFormat(string, AudioExtensions);

	return isAudioFormat;
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsUrlHttp(FString string)
{
	return string.StartsWith("http://", ESearchCase::IgnoreCase);
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsUrlHttps(FString string)
{
	return string.StartsWith("https://", ESearchCase::IgnoreCase);
}

bool Uenhanced_stringBPLibrary::enhanced_stringIsUrlSubdomainFormat(FString string, TArray<FString> subDomains)
{
	FString newString;
	FString stringSubDomain;
	bool isUrlFormat;

	isUrlFormat = enhanced_stringIsUrlFormat(string) == 0;
	if (!isUrlFormat) { return false; }

	newString = enhanced_stringRemoveHttpHttpsInUrl(string);

	stringSubDomain = enhanced_stringGetStringBeforeFirstChar(newString, ".");

	int i = 0;
	while (i < subDomains.Num() && stringSubDomain != subDomains[i])
	{
		i++;
	}

	isUrlFormat = i < subDomains.Num();

	return isUrlFormat;
}

bool Uenhanced_stringBPLibrary::enhanced_stringContainsLower(FString string)
{
	bool containsLower;
	int stringLength = enhanced_stringGetstringLength(string);

	int i = 0;
	while (i < stringLength && !enhanced_stringIsLower(string[i]))
	{
		i++;
	}

	containsLower = i < stringLength;

	return containsLower;
}

FDateTime Uenhanced_stringBPLibrary::enhanced_stringSetDateTimeDay(FDateTime dateTime, int day)
{
	int formatDay = day < 1 || day > 31 ? 1 : day;

	FDateTime newDateTime(dateTime.GetYear(), dateTime.GetMonth(), formatDay, dateTime.GetHour(), dateTime.GetMinute(), dateTime.GetSecond(), dateTime.GetMillisecond());

	return newDateTime;
}

FDateTime Uenhanced_stringBPLibrary::enhanced_stringSetDateTimeYear(FDateTime dateTime, int year)
{
	int formatYear = year < 1 || year > MAX_int32 ? 1 : year;

	FDateTime newDateTime(formatYear, dateTime.GetMonth(), dateTime.GetDay(), dateTime.GetHour(), dateTime.GetMinute(), dateTime.GetSecond(), dateTime.GetMillisecond());

	return newDateTime;
}

FDateTime Uenhanced_stringBPLibrary::enhanced_stringSetDateTimeMonth(FDateTime dateTime, int month)
{
	int formatMonth = month < 1 || month > 12 ? 1 : month;

	FDateTime newDateTime(dateTime.GetYear(), formatMonth, dateTime.GetDay(), dateTime.GetHour(), dateTime.GetMinute(), dateTime.GetSecond(), dateTime.GetMillisecond());

	return newDateTime;
}


FDateTime Uenhanced_stringBPLibrary::enhanced_stringSetDateTimeDate(FDateTime dateTime, int year, int month, int day)
{
	int formatYear = year < 1 || year > MAX_int32 ? 1 : year;
	int formatMonth = month < 1 || month > 12 ? 1 : month;
	int formatDay = day < 1 || day > 31 ? 1 : day;

	FDateTime newDateTime(formatYear, formatMonth, formatDay, dateTime.GetHour(), dateTime.GetMinute(), dateTime.GetSecond(), dateTime.GetMillisecond());

	return newDateTime;
}

FDateTime Uenhanced_stringBPLibrary::enhanced_stringSetDateTimeHour(FDateTime dateTime, int hour)
{
	int formatHour = hour < 0 || hour > 24 ? 0 : hour;

	FDateTime newDateTime(dateTime.GetYear(), dateTime.GetMonth(), dateTime.GetDay(), formatHour, dateTime.GetMinute(), dateTime.GetSecond(), dateTime.GetMillisecond());

	return newDateTime;
}

FDateTime Uenhanced_stringBPLibrary::enhanced_stringSetDateTimeMinute(FDateTime dateTime, int minute)
{
	int formatMinute = minute < 0 || minute > 60 ? 0 : minute;

	FDateTime newDateTime(dateTime.GetYear(), dateTime.GetMonth(), dateTime.GetDay(), dateTime.GetHour(), formatMinute, dateTime.GetSecond(), dateTime.GetMillisecond());

	return newDateTime;
}

FDateTime Uenhanced_stringBPLibrary::enhanced_stringSetDateTimeSecond(FDateTime dateTime, int second)
{
	int formatSecond = second < 0 || second > 60 ? 0 : second;

	FDateTime newDateTime(dateTime.GetYear(), dateTime.GetMonth(), dateTime.GetDay(), dateTime.GetHour(), dateTime.GetMinute(), formatSecond, dateTime.GetMillisecond());

	return newDateTime;
}

FDateTime Uenhanced_stringBPLibrary::enhanced_stringSetDateTimeMillisecond(FDateTime dateTime, int millisecond)
{
	int formatMillisecond = millisecond < 0 || millisecond > 60 ? 0 : millisecond;

	FDateTime newDateTime(dateTime.GetYear(), dateTime.GetMonth(), dateTime.GetDay(), dateTime.GetHour(), dateTime.GetMinute(), dateTime.GetSecond(), formatMillisecond);

	return newDateTime;
}

FDateTime Uenhanced_stringBPLibrary::enhanced_stringSetDateTimeTime(FDateTime dateTime, int hour, int minute, int second, int millisecond)
{
	int formatHour = hour < 0 || hour > 24 ? 0 : hour;
	int formatMinute = minute < 0 || minute > 60 ? 0 : minute;
	int formatSecond = second < 0 || second > 60 ? 0 : second;
	int formatMillisecond = millisecond < 0 || millisecond > 60 ? 0 : millisecond;

	FDateTime newDateTime(dateTime.GetYear(), dateTime.GetMonth(), dateTime.GetDay(), formatHour, formatMinute, formatSecond, formatMillisecond);

	return newDateTime;
}

TArray<FString> Uenhanced_stringBPLibrary::enhanced_stringOrderStringArrayByLength(TArray<FString> stringArray,
	bool ascending)
{
	TArray<FString> orderedStringArray;

	for(int i = 0; i < stringArray.Num(); i++)
	{
		int j = 0;
		while(j < orderedStringArray.Num() && (ascending ? stringArray[i].Len() > orderedStringArray[j].Len() : stringArray[i].Len() < orderedStringArray[j].Len()))
		{
			j++;
		}

		orderedStringArray.Insert(stringArray[i], j);
	}

	return orderedStringArray;
}

TArray<FString> Uenhanced_stringBPLibrary::enhanced_stringOrderStringArrayByAlphanumeric(TArray<FString> stringArray,
	bool ascending)
{
	TArray<FString> orderedStringArray;

	for (int i = 0; i < stringArray.Num(); i++)
	{
		int j = 0;
		while (j < orderedStringArray.Num() && (ascending ? stringArray[i] > orderedStringArray[j] : stringArray[i] < orderedStringArray[j]))
		{
			j++;
		}

		orderedStringArray.Insert(stringArray[i], j);
	}

	return orderedStringArray;
}

FString Uenhanced_stringBPLibrary::enhanced_stringFindLongestStringInArray(TArray<FString> stringArray)
{
	int longuestLenght = 0;
	int index = 0;

	for(int i = 0; i < stringArray.Num(); i++)
	{
		if(stringArray[i].Len() > longuestLenght)
		{
			longuestLenght = stringArray[i].Len();
			index = i;
		}
	}

	return stringArray[index];
}

FString Uenhanced_stringBPLibrary::enhanced_stringFindShortestStringInArray(TArray<FString> stringArray)
{

	if(stringArray.Num() < 1) { return ""; } // avoid crash
	
	int shortestLenght = stringArray[0].Len();
	int index = 0;

	for(int i = 0; i < stringArray.Num(); i++)
	{
		if(stringArray[i].Len() < shortestLenght)
		{
			shortestLenght = stringArray[i].Len();
			index = i;
		}
	}

	return stringArray[index];
}

int32 Uenhanced_stringBPLibrary::enhanced_stringCountOccurrencesOfSubstringInArray(TArray<FString> stringArray,
	FString substring)
{
	int occurences = 0;
	for(int i = 0; i < stringArray.Num(); i++)
	{
		occurences += enhanced_stringCountSubStringInString(substring, stringArray[i]);
		UE_LOG(LogTemp, Warning, TEXT(" %d"), occurences);
	}

	return occurences;
}

FString Uenhanced_stringBPLibrary::enhanced_stringClampStringByLength(FString string, int32 minLength,
	int32 maxLength)
{
	if(minLength < 0 || maxLength < 0)	{ return ""; }
	if(minLength > maxLength)			{ return ""; }

	return enhanced_stringClampString(string, minLength, maxLength);
}

TArray<FString> Uenhanced_stringBPLibrary::enhanced_stringClampStringArrayByLength(TArray<FString> stringArray,
                                                                               int32 minLength, int32 maxLength)
{
	TArray<FString> newStringArray = TArray<FString>();
	
	if(minLength < 0 || maxLength < 0)	{ return newStringArray; }
	if(minLength > maxLength)			{ return newStringArray; }

	for(int i = 0; i < stringArray.Num(); i++)
	{
		FString string = enhanced_stringClampString(stringArray[i], minLength, maxLength);

		if(!string.IsEmpty())
		{
			newStringArray.Add(string);
		}
	}

	return newStringArray;
}

TArray<FString> Uenhanced_stringBPLibrary::enhanced_stringFilterStringArrayByLength(TArray<FString> stringArray,
	int32 minLength, int32 maxLength)
{
	TArray<FString> newStringArray = TArray<FString>();
	
	if(minLength < 0 || maxLength < 0)	{ return newStringArray; }
	if(minLength > maxLength)			{ return newStringArray; }

	for(int i = 0; i < stringArray.Num(); i++)
	{
		if(stringArray[i].Len() >= minLength && stringArray[i].Len() <= maxLength)
		{
			newStringArray.Add(stringArray[i]);
		}
	}

	return newStringArray;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetDateTimeTimeAsString(FDateTime dateTime)
{
	FString newString;

	newString = " Hour=" + FString::FromInt(dateTime.GetHour());
	newString += " Minute=" + FString::FromInt(dateTime.GetMinute());
	newString += " Second=" + FString::FromInt(dateTime.GetSecond());
	newString += " Millisecond=" + FString::FromInt(dateTime.GetMillisecond());

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringGetDateTimeDateAsString(FDateTime dateTime)
{
	FString newString;

	newString = "Year=" + FString::FromInt(dateTime.GetYear());
	newString += " Month=" + FString::FromInt(dateTime.GetMonth());
	newString += " Day=" + FString::FromInt(dateTime.GetDay());

	return newString;
}

FString Uenhanced_stringBPLibrary::enhanced_stringCapitalizeWords(FString string, FString separator)
{
	int stringLength = enhanced_stringGetstringLength(string);
	int separatorLength = enhanced_stringGetstringLength(separator);
	
	if(stringLength < 1) { return string; }
	if (separatorLength < 1) { return string; }

	string[0] = enhanced_stringGetUpperCharacter(string[0]);

	for(int i = 1; i < stringLength; i++)
	{
		if(string[i - 1] == separator[0])
		{
			string[i] = enhanced_stringGetUpperCharacter(string[i]);
		}
		else
		{
			if(string[i] != separator[0])
			{
				string[i] = enhanced_stringGetLowerCharacter(string[i]);
			}
		}
	}

	return string;
	
}
