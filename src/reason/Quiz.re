open MaterialUi;

[@react.component]

let make = () => {

  let containerStyle = ReactDOMRe.Style.make(~marginTop = "110px", ());

  <Container style=containerStyle>
    <Form />
  </Container>
};