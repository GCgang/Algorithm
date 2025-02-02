// https://school.programmers.co.kr/learn/courses/30/lessons/118666

function solution(survey, choices) {
  const scores = {
    R: 0,
    T: 0,
    C: 0,
    F: 0,
    J: 0,
    M: 0,
    A: 0,
    N: 0,
  };

  const points = [0, 3, 2, 1, 0, 1, 2, 3];

  for (let i = 0; i < survey.length; i++) {
    let [disagree, agree] = survey[i].split('');
    let choice = choices[i];

    if (choice < 4) scores[disagree] += points[choice];
    if (choice > 4) scores[agree] += points[choice];
  }

  let result = '';

  result += scores['R'] >= scores['T'] ? 'R' : 'T';
  result += scores['C'] >= scores['F'] ? 'C' : 'F';
  result += scores['J'] >= scores['M'] ? 'J' : 'M';
  result += scores['A'] >= scores['N'] ? 'A' : 'N';

  return result;
}
