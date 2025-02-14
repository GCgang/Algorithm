function solution(k, dungeons) {
  let maxCount = 0;
  let visited = Array(dungeons.length).fill(false);

  function dfs(k, count) {
    maxCount = Math.max(maxCount, count);

    for (let i = 0; i < dungeons.length; i++) {
      let [required, consumed] = dungeons[i];

      if (!visited[i] && k >= required) {
        visited[i] = true;
        dfs(k - consumed, count + 1);
        visited[i] = false;
      }
    }
  }

  dfs(k, 0);
  return maxCount;
}
