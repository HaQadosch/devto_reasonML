exception PostError(string);

let post = (url: string, payload) => {
  let string_of_payload = payload |> Js.Json.object_ |> Js.Json.stringify;

  Js.Promise.(
    Fetch.fetchWithInit(
      url,
      Fetch.RequestInit.make(
        ~method_=Post,
        ~body=Fetch.BodyInit.make(string_of_payload),
        ~headers=Fetch.HeadersInit.make({"Content-type": "application/json"}),
        (),
      ),
    )
    |> then_(Fetch.Response.json)
    |> then_(response =>
         switch (Js.Json.decodeObject(response)) {
         | Some(decodedRes) =>
           switch (Js.Dict.get(decodedRes, "error")) {
           | Some(error) =>
             switch (Js.Json.decodeObject(error)) {
             | Some(decodedError) =>
               switch (Js.Dict.get(decodedError, "message")) {
               | Some(errorMessage) =>
                 switch (Js.Json.decodeString(errorMessage)) {
                 | Some(decodedErrorMessage) =>
                   reject(PostError(decodedErrorMessage))
                 | None => reject(PostError("Post Error"))
                 }
               | None => resolve(decodedRes)
               }
             | None => resolve(decodedRes)
             }
           | None => resolve(decodedRes)
           }
         | None => resolve(Js.Dict.empty())
         }
       )
  );
};
