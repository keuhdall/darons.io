open MaterialUi;

[@react.component]

let make = (~score) => {
  <Container>
    <Typography variant=`H2 align=`Center>"Bravo, tu as fini le test !"</Typography>
    <Typography variant=`H5 align=`Center>
      {"Ton score est de " ++ Js.Float.toString(score) ++ {(score > 1.0) ? " points" : " point"}}
    </Typography>
  </Container>
};