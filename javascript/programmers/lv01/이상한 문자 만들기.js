// https://school.programmers.co.kr/learn/courses/30/lessons/12930
function solution(s) {
  return s
    .split(' ')
    .map((word) => {
      let result = '';
      for (let i = 0; i < word.length; i++) {
        if (i % 2 === 0) {
          result += word[i].toUpperCase();
        } else {
          result += word[i].toLowerCase();
        }
      }
      return result;
    })
    .join(' ');
}
