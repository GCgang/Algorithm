// https://school.programmers.co.kr/learn/courses/30/lessons/49993
function solution(skill, skill_trees) {
  let cnt = 0;

  for (let tree of skill_trees) {
    let filtered = tree
      .split('')
      .filter((c) => skill.includes(c))
      .join('');

    if (skill.startsWith(filtered)) {
      cnt++;
    }
  }

  return cnt;
}

function solution2(skill, skill_trees) {
  let cnt = 0;

  for (let tree of skill_trees) {
    let q = skill.split('');
    let isValid = true;

    for (let c of tree) {
      if (!skill.includes(c)) continue;

      if (c === q[0]) {
        q.shift();
      } else {
        isValid = false;
        break;
      }
    }

    if (isValid) cnt++;
  }

  return cnt;
}
