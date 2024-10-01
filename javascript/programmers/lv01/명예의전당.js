// https://school.programmers.co.kr/learn/courses/30/lessons/138477
function solution(k, scoreList) {
  let hall = [];

  return scoreList.reduce((result, cur) => {
    hall.push(cur);
    hall = hall.sort((a, b) => b - a).slice(0, k);
    return [...result, Math.min(...hall)];
  }, []);
}
