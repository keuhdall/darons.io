open MaterialUi;

[@react.component]
let make = (~score) => {
  
  let rank = Ranks.getRank(score);

  let rankStyle = ReactDOMRe.Style.make(~marginTop="200px", ());
  let descriptionStyle = ReactDOMRe.Style.make(~marginTop="20px", ());

  <Container>
    <Typography variant=`H2 align=`Center style=rankStyle>
      {Ranks.getRankName(rank)}
    </Typography>
    <Typography variant=`H5 align=`Center style=descriptionStyle>
      {Ranks.getDescription(rank)}
    </Typography>
  </Container>
};