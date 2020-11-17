
type state = {
  answers: list(float)
};

let sum = answers => List.fold_left(((a,b) => a+.b), 0.0, answers);

[@react.component]
let make = () => {

  let (state, setState) = React.useState(() => {
    answers: []
  });

  let onChange = (~answer: option(float)) => {
    let newAnswers = switch answer {
    | Some(value) => [value, ...state.answers]
    | None        => List.tl(state.answers)
    };
    setState(_ => { answers: newAnswers });
  };

  let containerStyle = ReactDOMRe.Style.make(~marginTop = "110px", ());

  <MaterialUi.Container style=containerStyle>
    {(List.length(state.answers) >= List.length(Questions.all)) ? <Results score=sum(state.answers) /> : <Form onChange />}
  </MaterialUi.Container>
};