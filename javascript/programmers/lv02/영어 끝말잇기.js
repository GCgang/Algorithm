// https://school.programmers.co.kr/learn/challenges?order=recent&page=1&search=%EC%98%81%EC%96%B4
function solution(n, words) {
  const usedWords = new Set();

  usedWords.add(words[0]);

  for (let i = 1; i < words.length; i++) {
    let prev = words[i - 1];
    let curr = words[i];

    if (usedWords.has(curr) || prev[prev.length - 1] !== curr[0]) {
      let player = (i % n) + 1;
      let turn = Math.floor(i / n) + 1;

      return [player, turn];
    }

    usedWords.add(curr);
  }

  return [0, 0];
}
