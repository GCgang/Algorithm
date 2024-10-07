// https://school.programmers.co.kr/learn/courses/30/lessons/17681

function solution(n, arr1, arr2) {
  let map1 = [];
  let map2 = [];
  let result = new Array(n).fill('');

  map1 = arr1.map((e) => e.toString(2).padStart(n, '0'));
  map2 = arr2.map((e) => e.toString(2).padStart(n, '0'));

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < n; ++j) {
      if (map1[i][j] !== '0' || map2[i][j] !== '0') {
        result[i] += '#';
      } else {
        result[i] += ' ';
      }
    }
  }
  return result;
}
