//https://school.programmers.co.kr/learn/courses/30/lessons/67256
function solution(numbers, hand) {
  const keypads = {
    1: [0, 0],
    2: [0, 1],
    3: [0, 2],
    4: [1, 0],
    5: [1, 1],
    6: [1, 2],
    7: [2, 0],
    8: [2, 1],
    9: [2, 2],
    '*': [3, 0],
    0: [3, 1],
    '#': [3, 2],
  };

  function getDistance(pos1, pos2) {
    return Math.abs(pos1[0] - pos2[0]) + Math.abs(pos1[1] - pos2[1]);
  }

  let leftPos = keypads['*'];
  let rightPos = keypads['#'];
  let result = '';

  for (let num of numbers) {
    let target = keypads[num];

    if ([1, 4, 7].includes(num)) {
      result += 'L';
      leftPos = target;
    } else if ([3, 6, 9].includes(num)) {
      result += 'R';
      rightPos = target;
    } else {
      let leftDist = getDistance(leftPos, target);
      let rightDist = getDistance(rightPos, target);

      if (leftDist < rightDist) {
        result += 'L';
        leftPos = target;
      } else if (rightDist < leftDist) {
        result += 'R';
        rightPos = target;
      } else {
        if (hand === 'right') {
          result += 'R';
          rightPos = target;
        } else {
          result += 'L';
          leftPos = target;
        }
      }
    }
  }
  return result;
}
