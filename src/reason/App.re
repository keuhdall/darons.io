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
  | ["quiz"]  => mkPage(<Quiz />)
  | _         => mkPage(<Home />)
  };

};