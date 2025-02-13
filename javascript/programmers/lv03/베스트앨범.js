function solution(genres, plays) {
  const genreMap = new Map();
  const songMap = new Map();

  for (let i = 0; i < genres.length; i++) {
    let genre = genres[i];
    let play = plays[i];

    genreMap.set(genre, (genreMap.get(genre) || 0) + play);

    if (!songMap.has(genre)) songMap.set(genre, []);
    songMap.get(genre).push({ index: i, play });
  }

  let genreArray = [...genreMap.entries()];
  genreArray.sort((a, b) => b[1] - a[1]);
  let sortedGenres = genreArray.map((entry) => entry[0]);

  let result = [];

  for (let genre of sortedGenres) {
    let sortedSongs = songMap
      .get(genre)
      .sort((a, b) => b.play - a.play || a.index - b.index);

    result.push(sortedSongs[0].index);
    if (sortedSongs.length > 1) result.push(sortedSongs[1].index);
  }

  return result;
}
