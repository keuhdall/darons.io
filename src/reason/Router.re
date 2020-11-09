[@react.component]

let make = () => {
  let url = ReasonReact.Router.useUrl();

  let mkPage = component => {
    <React.StrictMode>
      <Navbar />
      component
    </React.StrictMode>
  }

  switch (url.path) {
  | []        => mkPage(<Home />)
  | ["quiz"]  => mkPage(<Quiz />)
  | _         => <NotFound />
  };

};