// https://school.programmers.co.kr/learn/courses/30/lessons/160586
function solution(keymap, targets) {
  const result = [];
  const minKeyMap = new Map();

  for (let key of keymap) {
    for (let i = 0; i < key.length; i++) {
      let char = key[i];
      if (!minKeyMap.has(char) || minKeyMap.get(char) > i + 1) {
        minKeyMap.set(char, i + 1);
      }
    }
  }

  for (let target of targets) {
    let pressCnt = 0;
    for (let char of target) {
      if (!minKeyMap.get(char)) {
        pressCnt = -1;
        break;
      } else {
        pressCnt += minKeyMap.get(char);
      }
    }
    result.push(pressCnt);
  }

  return result;
}
