open MaterialUi;

[@react.component]

let make = () => {

  let titleStyle = ReactDOMRe.Style.make(~marginTop = "110px", ());

  <Container>
    <Typography variant=`H1 align=`Center style=titleStyle>
      "C'est l'heure du quiz fdp"
    </Typography>
  </Container>
};