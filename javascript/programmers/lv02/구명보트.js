//school.programmers.co.kr/learn/courses/30/lessons/42885
https: function solution(people, limit) {
  people.sort((a, b) => a - b);

  let boats = 0;
  let left = 0;
  let right = people.length - 1;

  while (left <= right) {
    if (people[right] + people[left] <= limit) {
      left++;
    }
    right--;
    boats++;
  }

  return boats;
}
