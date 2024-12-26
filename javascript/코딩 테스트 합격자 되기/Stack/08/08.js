function solution(arr) {
  const stack = [];
  for (bracket of arr) {
    if (bracket == '(') {
      stack.push(bracket);
    } else if (bracket == ')') {
      if (stack.length === 0) {
        return false;
      } else {
        stack.pop();
      }
    }
  }
  return !stack.length;
}

// console.log(solution("(())()")); // 반환값 : true
// console.log(solution("((())()")); // 반환값 : false
