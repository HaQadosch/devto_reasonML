let countWordsInString = text => {
  let spacesRegEx = [%re "/\s+/"];

  switch (text) {
  | "" => 0
  | noneEmptyText =>
    noneEmptyText
    |> Js.String.trim
    |> Js.String.splitByRe(spacesRegEx)
    |> Js.Array.length
  };
};
