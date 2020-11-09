open MaterialUi;

[@react.component]

let make = () => {
  let appbarStyle = ReactDOMRe.Style.make(
    ~height = "90px",
    ()
  );

  <AppBar style=appbarStyle>
    <Typography variant=`H3 align=`Center>"Darons.io"->React.string</Typography>
    <Typography variant=`H5 align=`Center>"Teste ton niveau de daronisation !"->React.string</Typography>
  </AppBar>
};