// https://school.programmers.co.kr/learn/courses/30/lessons/131128

// O(N+M)
function solution(X, Y) {
  const result = [];
  const arrX = Array(10).fill(0);
  const arrY = Array(10).fill(0);

  for (let c of X) arrX[c]++;
  for (let c of Y) arrY[c]++;

  for (let i = 9; i >= 0; i--) {
    let cnt = Math.min(arrX[i], arrY[i]);
    result.push(String(i).repeat(cnt));
  }

  const answer = result.join('');

  if (answer.length === 0) return '-1';
  if (answer[0] === '0') return '0';

  return answer;
}

//O(N+M)
function solution2(X, Y) {
  let countX = new Map();
  let countY = new Map();

  for (let char of X) countX.set(char, (countX.get(char) || 0) + 1);
  for (let char of Y) countY.set(char, (countY.get(char) || 0) + 1);

  let result = [];
  for (let i = 9; i >= 0; i--) {
    let key = String(i);
    if (countX.has(key) && countY.has(key)) {
      let count = Math.min(countX.get(key), countY.get(key));
      result.push(key.repeat(count));
    }
  }

  const answer = result.join('');

  if (answer.length === 0) return '-1';
  if (answer[0] === '0') return '0';

  return answer;
}

//O(NlogN)+O(MlogM)
function solution3(X, Y) {
  const result = [];
  const arrX = X.split('').sort((a, b) => b - a);
  const arrY = Y.split('').sort((a, b) => b - a);

  let i = 0,
    j = 0;

  while (i < arrX.length && j < arrY.length) {
    if (arrX[i] === arrY[j]) {
      result.push(arrX[i]);
      i++;
      j++;
    } else if (arrX[i] > arrY[j]) {
      i++;
    } else {
      j++;
    }
  }

  if (result.length === 0) return '-1';
  if (result[0] === '0') return '0';

  return result.join('');
}
