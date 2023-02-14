package com.server.app.controller;


import com.server.app.exception.ApplicationExceptions;
import com.server.app.exception.SuccessMessage;
import com.server.app.model.User;
import com.server.app.service.IUserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.List;

@RestController
@RequestMapping("/server/user")
@Validated
public class UserController {

    @Autowired
    private IUserService service;

    @RequestMapping("/findAll")
    public List<User> findAll() {
        List<User> entities = service.findAll();
        if (entities.size() > 0) {
            return entities;
        } else {
            throw new ApplicationExceptions("controller.user.findAll.isNull");
        }
    }

    @GetMapping("/findByUsername/{username}")
    public User findByUsername(@PathVariable("username") String username) {
        if (username.length() > 0) {
            User entity = service.findByUsername(username);
            if (entity != null) {
                return entity;
            }
            throw new ApplicationExceptions("controller.user.username.isNull");
        } else {
            throw new ApplicationExceptions("controller.user.username.invalid");
        }
    }

    @GetMapping("/findByUsernameAndPassword")
    public User findByFullName(@RequestParam String username, @RequestParam String password) {
        if (username.length() > 0 && password.length() > 0) {
            User entity = service.findByUsernameAndPassword(username, password);
            if (entity != null) {
                return entity;
            }
            throw new ApplicationExceptions("controller.UsernameAndPassword.isNull");
        } else {
            throw new ApplicationExceptions("controller.UsernameAndPassword.invalid");
        }
    }

    @PostMapping("/save")
    public void save(@Valid @RequestBody(required = false) User user) {
        User entity = service.findByUsername(user.getUsername());
        if (entity != null) {
            throw new ApplicationExceptions("controller.user.username.exist");
        }
        try {
            service.save(user);
        } catch (Exception e) {
            throw new ApplicationExceptions("controller.user.save.failed");
        }
        throw new SuccessMessage("controller.user.save.success");
    }
}
