
type answer = Yes | No;

type state = {
  questionIndex: int,
  answers: list(float)
};

let questions = Array.of_list(Questions.all);

let mkRadioLabel = str => <MaterialUi.Typography variant=`H5>str</MaterialUi.Typography>;

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
    questionIndex: 0,
    answers: []
  });

  let sum = answers => List.fold_left(((a,b) => a+.b), 0.0, answers);

  let nextQuestion = answer => {
    let questionScore = answer == Yes ? questions[state.questionIndex].coef : 0.0;
    setState(s => s.questionIndex == Array.length(questions)-1 ? s : {
        questionIndex: s.questionIndex+1,
        answers: [questionScore, ...s.answers]
    })
  };
  
  let prevQuestion = () => {
    setState(s => s.questionIndex == 0 ? s : {
      questionIndex: s.questionIndex-1,
      answers: List.tl(s.answers)
    })
  };

  <MaterialUi.FormControl style=formStyle>
    <MaterialUi.Typography variant=`H2 align=`Justify style=typoStyle>
      questions[state.questionIndex].content
    </MaterialUi.Typography>
    <div style=buttonContainerStyle>
      <MaterialUi.ButtonGroup variant=`Outlined size=`Large style=buttonGroupStyle>
        <MaterialUi.Button onClick=(_ => nextQuestion(Yes)) color=`Primary style=questionButtonStyle>"Oui"</MaterialUi.Button>
        <MaterialUi.Button onClick=(_ => nextQuestion(No)) color=`Primary style=questionButtonStyle>"Non"</MaterialUi.Button>
      </MaterialUi.ButtonGroup>
      <MaterialUi.Button onClick=(_ => prevQuestion()) variant=`Outlined color=`Primary style=returnButtonStyle>
        {j|Question précédente|j}
      </MaterialUi.Button>
    </div>
  </MaterialUi.FormControl>
};