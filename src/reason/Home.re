open Utils;
open MaterialUi;

requireCSS("src/styles/home.css");

[@react.component]

let make = () => {

  let mainContainerStyle = ReactDOMRe.Style.make(~marginTop = "110px", ());

  <Container maxWidth=Container.MaxWidth.md style=mainContainerStyle>
    <Typography variant=`H4>
      "test mdr"
    </Typography>
    <Box textAlign=Box.Value.string("center")>
      <Button variant=`Contained onClick=(_ => ReasonReact.Router.push("quiz"))>
        "Faire le test !"
      </Button>
    </Box>
  </Container>
};