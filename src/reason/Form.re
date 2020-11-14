open MaterialUi;

type state = {
  questionIndex: int
};

let questions = [|
  {j|Est-ce que tu réalises une liste de courses avant d’aller au supermarché ?|j},
  {j|Est-ce que tes musiques préférées passent sur Nostalgie ?|j},
  {j|Est-ce que tu vas au marché ?|j}
|];

let mkRadioLabel = str => <Typography variant=`H5>str</Typography>;

[@react.component]
let make = () => {

  let typoStyle = ReactDOMRe.Style.make(~textAlign="center", ());
  let buttonContainerStyle = ReactDOMRe.Style.make(
      ~display="flex",
      ~flexDirection="column",
      ~alignItems="center",
      ~marginTop="200px",
      ~position="absolute",
      ()
    );
    let formStyle = ReactDOMRe.Style.make(
      ~display="flex",
      ~flexDirection="column",
      ~alignItems="center",
      ()
    );
    let buttonGroupStyle = ReactDOMRe.Style.make(~minWidth="400px", ());
    let questionButtonStyle = ReactDOMRe.Style.make(~width="150%", ~height="150%", ());
    let returnButtonStyle = ReactDOMRe.Style.make(~marginTop="10px", ~maxWidth="600px", ());

  let (state, setState) = React.useState(() => {
    questionIndex: 0
  });

  let nextQuestion = () => setState(s => s.questionIndex == Array.length(questions)-1 ? s : {...s, questionIndex: s.questionIndex+1});
  let prevQuestion = () => setState(s => s.questionIndex == 0 ? s : {...s, questionIndex: s.questionIndex-1});

  <FormControl style=formStyle>
    <Typography variant=`H2 align=`Justify style=typoStyle>
      questions[state.questionIndex]
    </Typography>
    <div style=buttonContainerStyle>
      <ButtonGroup variant=`Outlined size=`Large style=buttonGroupStyle>
        <Button onClick=(_ => nextQuestion()) color=`Primary style=questionButtonStyle>"Oui"</Button>
        <Button onClick=(_ => nextQuestion()) color=`Primary style=questionButtonStyle>"Non"</Button>
      </ButtonGroup>
      <Button onClick=(_ => prevQuestion()) variant=`Outlined color=`Primary style=returnButtonStyle>
        {j|Question précédente|j}
      </Button>
    </div>
  </FormControl>
};