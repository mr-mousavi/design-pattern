package com.server.app.service.impl;

import com.server.app.model.User;
import com.server.app.repository.IUserRepository;
import com.server.app.service.IUserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.transaction.Transactional;
import java.util.List;

@Service
@Transactional
public class UserService implements IUserService {

    @Autowired
    private IUserRepository repository;

    @Override
    public List<User> findAll() {
        return repository.findAll();
    }

    @Override
   public User findByUsername(String username) {
        return repository.findByUsername(username);
    }

    @Override
    public User findByUsernameAndPassword(String username, String password){
        return repository.findByUsernameAndPassword(username, password);
    }

    @Override
    public void save(User user){
        repository.save(user);
    }

}
