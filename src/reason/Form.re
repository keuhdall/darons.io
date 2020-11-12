open MaterialUi;


type answer = Yes | No;
type state = {
  questionIndex: int,
  questionAnswer: answer
};

let questions = [|
  {j|Est-ce que tu réalises une liste de courses avant d’aller au supermarché ?|j},
  {j|Est-ce que tes musiques préférées passent sur Nostalgie ?|j},
  {j|Est-ce que tu vas au marché ?|j}
|];

[@react.component]
let make = () => {

  let typoStyle = ReactDOMRe.Style.make(~textAlign="center", ());

  let (state, setState) = React.useState(() => {
    questionIndex: 0,
    questionAnswer: Yes
  });

  <FormControl>
    <Typography variant=`H2 align=`Justify style=typoStyle>
      questions[state.questionIndex]
    </Typography>
    <RadioGroup name="answer" row=true>
      <FormControlLabel control={<Radio />} label="Oui"->React.string />
      <FormControlLabel control={<Radio />} label="Non"->React.string />
    </RadioGroup>
    <Button variant=`Contained onClick=(_ => setState(s => {...s, questionIndex: s.questionIndex+1}))>
      {(state.questionIndex < Array.length(questions) -1) ? "Question suivante" : "Finir le test !"}
    </Button>
  </FormControl>
};