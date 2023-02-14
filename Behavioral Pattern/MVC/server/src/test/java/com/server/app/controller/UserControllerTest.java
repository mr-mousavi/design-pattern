package com.server.app.controller;

import com.server.app.common.BaseControllerTest;
import com.server.app.data.GetUserData;
import com.server.app.map.UserMapper;
import com.server.app.model.User;
import com.server.app.service.IUserService;
import com.server.app.view.UserView;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;

import java.io.IOException;

public class UserControllerTest extends BaseControllerTest {

    private final static String BASE_PATH = "/server/user";

    @Autowired
    private IUserService service;

    @Override
    protected String mapperName() {
        return User.class.getSimpleName();
    }

    @Test
    public void save() throws IOException {
        User entity = GetUserData.getUserData("mousavi", "admin", "1234567890", "admin123");
        setUserAndDate(entity);
        UserView view = (UserView) mapper.toView(entity, UserMapper.class);
        Object response = api.postForEntity(BASE_PATH + "/save", view, Object.class).getBody();
        write(response);
    }

}
