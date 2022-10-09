const wordInputEle = document.getElementById("word-input");
const submitBtnEle = document.getElementById("submit-btn");
const wordCountEle = document.getElementById("word-count");
const charCountEle = document.getElementById("char-count");

submitBtnEle.addEventListener("click", () => {
  const textInput = wordInputEle.value;
  const charCount = textInput.replaceAll(" ", "").length;
  const wordArray = textInput.split(" ");
  wordArrayLen = findWordLen(wordArray);
  wordCountEle.innerText = wordArrayLen;
  charCountEle.innerText = charCount;
});

const findWordLen = (wordArray) => {
  let wordLen = 0;
  wordArray.forEach((word) => {
    if (isWord(word)) {
      wordLen += 1;
    }
  });
  return wordLen;
};

const isWord = (word) => {
  if (word.length >= 2 && word.length <= 10) {
    return true;
  }
  return false;
};
