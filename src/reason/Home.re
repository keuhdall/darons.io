open MaterialUi;

[@react.component]

let make = () => {

  let mainContainerStyle = ReactDOMRe.Style.make(~marginTop = "110px", ());
  let textStyle = ReactDOMRe.Style.make(~fontStyle="italic", ());
  let explainationsStyle = ReactDOMRe.Style.make(~marginTop="30px", ~whiteSpace="pre-wrap", ());
  let buttonStyle = ReactDOMRe.Style.make(~marginTop="50px", ());

  <Container maxWidth=Container.MaxWidth.md style=mainContainerStyle>
    <Typography variant=`H4>
      "Daronisation (nf):"
    </Typography>
    <Typography variant=`H5 align=`Justify style=textStyle>
      {j|
      Processus évolutif à moyen ou long terme vécu par les jeunes adultes qui tend à responsabiliser les individus,
      consciemment ou non, les menant ainsi à adopter la posture et les comportements caractéristiques regroupés sous l’étiquette
      « daron » ou « daronne ».
      |j}
    </Typography>
    <Typography variant=`H5 align=`Justify style=explainationsStyle>
      {j|
Dans notre société du 21e Siècle, nombre d'entres nous, jeunes adultes entre 20 et 30 ans se découvrent être choqués par nos nouveaux besoins d'adultes et notre incompréhension grandissantes des jeunes d'aujourd'hui.
La question se pose: serions-nous devenus des Darons ?

Avec ce test, vous découvrirez votre niveau de daronisation grâce à notre Darometre™, approuvé par la communauté scientifique.
      |j}
    </Typography>
    <Box textAlign=Box.Value.string("center")>
      <Button variant=`Contained onClick=(_ => ReasonReact.Router.push("quiz")) style=buttonStyle>
        "Faire le test !"
      </Button>
    </Box>
  </Container>
};