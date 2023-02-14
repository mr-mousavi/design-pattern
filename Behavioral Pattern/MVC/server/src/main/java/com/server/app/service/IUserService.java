package com.server.app.service;

import com.server.app.model.User;

import java.util.List;

public interface IUserService {

    List<User> findAll();

    User findByUsername(String username);

    User findByUsernameAndPassword(String username, String password);

    void save(User user);
}
