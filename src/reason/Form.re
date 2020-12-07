open Questions;
open MaterialUi;

type state = {
  questionIndex: int
};

let questions = Array.of_list(Questions.all);
let mkRadioLabel = str => <Typography variant=`H5>str</Typography>;

[@react.component]
let make = (~onChange) => {

  let typoStyle = ReactDOMRe.Style.make(~marginTop="150px", ~textAlign="center", ());
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
  let buttonGroupStyle = ReactDOMRe.Style.make(~marginTop="180px", ~minWidth="400px", ());
  let questionButtonStyle = ReactDOMRe.Style.make(~width="150%", ~height="150%", ());
  let returnButtonStyle = ReactDOMRe.Style.make(~marginTop="20px", ~maxWidth="600px", ());
  let progressBarStyle = ReactDOMRe.Style.make(~marginTop="520px", ~position="absolute", ~width="80vw", ());

  let (state, setState) = React.useState(() => {
    questionIndex: 0
  });

  let nextQuestion = answer => {
    let questionScore = answer == Yes ? questions[state.questionIndex].coef : 0.0;
    setState(s => s.questionIndex == Array.length(questions)-1 ? s : { questionIndex: s.questionIndex+1 });
    onChange(~answer=Some(questionScore));
  };

  let prevQuestion = () => {
    setState(s => s.questionIndex == 0 ? s : { questionIndex: s.questionIndex-1 });
    onChange(~answer=Some(0.0));
  };

  let progress = Js.Int.toFloat(state.questionIndex) /. Js.Int.toFloat(Questions.length) *. 100.0;

  <FormControl style=formStyle>
    <Typography variant=`H2 align=`Justify style=typoStyle>
      questions[state.questionIndex].content
    </Typography>
    <div style=buttonContainerStyle>
      <ButtonGroup variant=`Outlined size=`Large style=buttonGroupStyle>
        <Button onClick=(_ => nextQuestion(Yes)) color=`Primary style=questionButtonStyle>"Oui"</Button>
        <Button onClick=(_ => nextQuestion(No)) color=`Primary style=questionButtonStyle>"Non"</Button>
      </ButtonGroup>
      <Button onClick=(_ => prevQuestion()) variant=`Outlined color=`Primary style=returnButtonStyle>
        {j|Question précédente|j}
      </Button>
    </div>
    <LinearProgress variant=`Determinate value=Number.float(progress) style=progressBarStyle />
  </FormControl>
};
