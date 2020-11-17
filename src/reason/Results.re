open MaterialUi;

[@react.component]
let make = (~score) => {
  
  let rank = Ranks.getRank(score);

  <Container>
    <Typography variant=`H2 align=`Center>
      {Ranks.getRankName(rank)}
    </Typography>
    <Typography variant=`H5 align=`Center>
      {Ranks.getDescription(rank)}
    </Typography>
  </Container>
};