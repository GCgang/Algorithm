function isCorrectBracket(s) {
  const stack = [];
  for (const bracket of s) {
    if (bracket === '(' || bracket === '[' || bracket === '{') {
      stack.push(bracket);
    } else {
      if (stack.length === 0) {
        return false;
      }
      const top = stack[stack.length - 1];
      if (bracket === ')') {
        if (top !== '(') {
          return false;
        }
      } else if (bracket === ']') {
        if (top !== '[') {
          return false;
        }
      } else if (bracket === '}') {
        if (top !== '{') {
          return false;
        }
      }
      stack.pop();
    }
  }
  return stack.length === 0;
}

function rotate(s) {
  return s.slice(1) + s[0];
}

function solution(s) {
  let count = 0;
  for (let i = 0; i < s.length; ++i) {
    if (isCorrectBracket(s)) {
      count++;
    }
    s = rotate(s);
  }
  return count;
}
