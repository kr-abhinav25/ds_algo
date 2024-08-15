# https://leetcode.com/problems/text-justification/

from typing import List

class Solution:

  def justifyLine(self, words, startWordIndex, endWordIndex, maxWidth, charactersCount):
    sentence = ""
    if (startWordIndex == endWordIndex):
      sentence = words[startWordIndex] + " " * (maxWidth - len(words[startWordIndex]))
    else:
      # wordCount should be endWordIndex - startWordIndex + 1
      # but we don't need to consider the last word to calculate
      # spaces so we skip +1.
      wordCount = endWordIndex - startWordIndex
      spaceCount = (maxWidth - charactersCount)
      extraSpaces = spaceCount % wordCount
      spaceAfterEachWord = spaceCount // wordCount
      if extraSpaces == 0: #spaces can be evenly distributed
        sentence = (" " * spaceAfterEachWord).join(words[startWordIndex:endWordIndex + 1])
      else:
        sentence = (((" " * spaceAfterEachWord) + " ").join(words[startWordIndex:(startWordIndex + extraSpaces) + 1]) + 
                    " " * spaceAfterEachWord +
                  (" " * spaceAfterEachWord).join(words[(startWordIndex + extraSpaces + 1):endWordIndex + 1]))
    
    return sentence


  def justifyLastLine(self, words, startWordIndex, endWordIndex, maxWidth):
    sentence = ""
    if (startWordIndex == endWordIndex):
      sentence = words[startWordIndex] + " " * (maxWidth - len(words[startWordIndex]))
    else:
      sentence = (" ").join(words[startWordIndex:endWordIndex + 1])
      sentence = sentence + (" " * (maxWidth - len(sentence)))
    return sentence


  def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
    result = []
    currentLineLength = 0
    currentLength = 0
    wordsInLine = 0
    currentWordIndex = 0
    startWordIndex = 0
    endWordIndex = 0
    charactersCount = 0
    charactersCountPerLine = 0
    wordsLength = len(words)
    while (currentWordIndex < wordsLength):
      charactersCount = len(words[currentWordIndex])
      currentLength = currentLineLength + charactersCount + wordsInLine
      if currentLength <= maxWidth:
        currentLineLength = currentLength
        endWordIndex = currentWordIndex
        charactersCountPerLine += charactersCount
        currentWordIndex += 1
        wordsInLine = 1
      else:
        result.append(self.justifyLine(words, startWordIndex, endWordIndex, maxWidth, charactersCountPerLine))
        startWordIndex = endWordIndex = currentWordIndex
        currentLineLength = wordsInLine = 0
        currentLength = 0
        charactersCountPerLine = 0

    if currentLength > 0:
      result.append(self.justifyLastLine(words, startWordIndex, endWordIndex, maxWidth))
      
    return result
  
# sol = Solution()
# result = sol.fullJustify(words = ["Science","is","what","we","understand",
#                          "well","enough","to","explain","to","a","computer.",
#                          "Art","is","everything","else","we","do"], maxWidth = 20)

# print(result)

# sol = Solution()
# result = sol.fullJustify(words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16)
# print(result)

# sol = Solution()
# result = sol.fullJustify(words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16)
# print(result)

# sol = Solution()
# result = sol.fullJustify(words = ["This", "is", "an"], maxWidth = 16)
# print(result)

sol = Solution()
result = sol.fullJustify(words = ["a", "b", "c", "d", "aaaaaaaaaaaaa"], maxWidth = 14)
print(result)