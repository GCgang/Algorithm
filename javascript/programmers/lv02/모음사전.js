// https://school.programmers.co.kr/learn/courses/30/lessons/84512
function solution(word) {
  const vowels = ['A', 'E', 'I', 'O', 'U'];
  let dictionary = [];

  function generateWords(current) {
    if (current.length > 5) return;

    dictionary.push(current);
    for (let v of vowels) {
      generateWords(current + v);
    }
  }

  generateWords('');
  dictionary.sort();

  return dictionary.indexOf(word);
}
