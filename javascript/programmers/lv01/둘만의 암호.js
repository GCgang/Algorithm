// https://school.programmers.co.kr/learn/courses/30/lessons/155652

function solution(s, skip, index) {
  const skipSet = new Set(skip);
  const validAlphabet = [];

  for (i = 0; i < 26; i++) {
    let char = String.fromCharCode(97 + i);
    if (!skipSet.has(char)) {
      validAlphabet.push(char);
    }
  }

  let result = '';

  for (let c of s) {
    let curIndex = validAlphabet.indexOf(c);
    let newIndex = (curIndex + index) % validAlphabet.length;
    result += validAlphabet[newIndex];
  }

  return result;
}

function solution2(s, skip, index) {
  const alphabet = [...'abcdefghijklmnopqrstuvwxyz'].filter(
    (c) => !skip.includes(c)
  );
  return s
    .split('')
    .map((c) => alphabet[(alphabet.indexOf(c) + index) % alphabet.length])
    .join('');
}
