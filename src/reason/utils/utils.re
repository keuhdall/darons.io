[@bs.val] external requireCSS: string => unit = "require";

[@bs.val] external requireAssetURI: string => string = "require";

let dangerousHtml: string => Js.t('a) = html => {"__html": html};