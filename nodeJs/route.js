function route(handle, pathname, response){
    console.log("pathname : " + pathname);
    
    if(typeof handle[pathname] === 'function'){
        handle[pathname](response);
    }else{
        handle['noting'](response);
    }
}

exports.route = route;