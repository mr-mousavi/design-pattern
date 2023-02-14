package com.server.app.data;

import com.server.app.enums.ActiveType;
import com.server.app.model.User;

public class GetUserData {

    public static User getUserData(String name, String username, String authKey, String password ){
        User user =new User();
        user.setUsername(username);
        user.setAuthKey(authKey);
        user.setName(name);
        user.setPassword(password);
        user.setStatus(ActiveType.ENABLED.getValue());
        return user;
    }
}
